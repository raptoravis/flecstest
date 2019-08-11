#include <flecstest.h>

typedef struct Position {
    float x;
    float y;
} Position;

typedef int32_t Speed;

void Move(ecs_rows_t *rows) {
    Position *p = ecs_column(rows, Position, 1);
    Speed *s = ecs_column(rows, Speed, 2);
    
    for (int i = 0; i < rows->count; i ++) {
        p[i].x += s[i] * rows->delta_time;
        p[i].y += s[i] * rows->delta_time;
    }
}

int main(int argc, char *argv[]) {
    ecs_world_t *world = ecs_init();

    /* Register components and systems */
    ECS_COMPONENT(world, Position);
    ECS_COMPONENT(world, Speed);
    ECS_SYSTEM(world, Move, EcsOnUpdate, Position, Speed);
    ECS_ENTITY(world, MyEntity, Position, Speed);

    /* Limit application to 60 FPS */
    ecs_set_target_fps(world, 60);

    /* Progress world in main loop (invokes Move system) */
    while (ecs_progress(world, 0));

    return ecs_fini(world);
}
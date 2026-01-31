#include <logger/logger.h>

int main() {
    struct LOGGER logger = INIT_LOGGER("main", "logs", "main.log", TRUE);

    LOG(logger, "Starting logger...", INFO, TRUE);
    printf("Hello, World!\n");
    LOG(logger, "Stopping logger...", INFO, TRUE);

    EXIT_LOGGER(&logger);
    return 0;
}

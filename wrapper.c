
// Import C headers for rust API
#include <pthread.h>
#include "myrustlib/gifski.h"

/* data to pass to encoder thread */
typedef struct {
  const char * path;
  gifski * g;
} gifski_encoder_thread_info;

/* gifski_write() blocks until main thread calls gifski_end_adding_frames() */
void * gifski_encoder_thread(void * data){
  gifski_encoder_thread_info * info = data;
  gifski_write(info->g, info->path);
  gifski_drop(info->g);
  return NULL;
}

#include <nuttx/config.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <poll.h>
#include <arch/chip/gnss.h>


FILE *fp = NULL;
char current_filename[100];
/*
NMEA_OUTPUT_CB funcs;
*/
/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define GNSS_POLL_FD_NUM          1
#define GNSS_POLL_TIMEOUT_FOREVER -1
#define MY_GNSS_SIG               18

/****************************************************************************
 * Private Types
 ****************************************************************************/

struct cxd56_gnss_dms_s
{
  int8_t   sign;
  uint8_t  degree;
  uint8_t  minute;
  uint32_t frac;
};

/****************************************************************************
 * Private Data
 ****************************************************************************/

/*
static uint32_t                         posfixflag;
static struct cxd56_gnss_positiondata_s posdat;
*/


char get_current_time(void){
	/*
	time_t t = time(NULL);
	return current_time;
	*/
	char current_time = "20201203";
	
	return current_time;
}


void log_open(char *filename){
  printf("Open %s\n", filename);
  fp = fopen(filename, "a");
  if (fp == NULL) {
    printf("Open error %s\n", filename);
  }
}

void log_write(){
	if (fp == NULL){
		//sprintf(current_filename, "/mnt/sd0/%s.nmea",get_current_time());
		sprintf(current_filename, "/mnt/sd0/%04d.nmea","2020");
		log_open(current_filename);
		printf("%s\n","open!!!");
	}
	printf("\n%s\n",fp);
	printf("%s\n","up is fp!!");
}

int main(int argc, FAR char *argv[])
{
	log_write();
	/*
	int      fd;
	int      ret;
	int      posperiod;
	sigset_t mask;
	struct cxd56_gnss_signal_setting_s setting;
	
	board_gpio_config(97, 0, false, true, 0);
	printf("Hello, GPIO!\n");

	for(int i=0; i<10; i++){
	    board_gpio_write(97, 1);
	    usleep(100*100);
	    board_gpio_write(97, 0);
	    usleep(100*100);
	}
	sigemptyset(&mask);
	sigaddset(&mask, MY_GNSS_SIG);
	ret = sigprocmask(SIG_BLOCK, &mask, NULL);
	if (ret != OK)
	{
	printf("sigprocmask failed. %d\n", ret);
	}

	set_satellite = CXD56_GNSS_SAT_QZ_L1S |CXD56_GNSS_SAT_QZ_L1CA ;

	ret = ioctl(fd, CXD56_GNSS_IOCTL_SELECT_SATELLITE_SYSTEM, set_satellite);

	printf(">Hour:%d, minute:%d, sec:%d, usec:%d\n",
        posdat.receiver.time.hour, posdat.receiver.time.minute,
        posdat.receiver.time.sec, posdat.receiver.time.usec);
	*/
}  

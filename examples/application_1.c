/*
 * This is one of log4c example programs.
 *
 * Notice how no relationships between the category and a certain
 * priority, appender, or formatter are coded here.  These are all left
 * to the log4crc config file so they can be chaned without recompiling
 * 
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <log4c.h>


/*#define	log_debug(x) log4c_category_log(mycat, LOG4C_PRIORITY_DEBUG, x)	[>  <]*/

int 
main(int argc, char** argv) {
    log4c_category_t* mycat = NULL;

    log4c_init();
    mycat = log4c_category_get("test-project");

    int a = 4;
    /*log_debug("yueyang test!%d", a);*/
    log4c_category_log(mycat, LOG4C_PRIORITY_FATAL, "yueyang test.");
    log4c_category_log(mycat, LOG4C_PRIORITY_DEBUG, "yueyang test.");
    log4c_category_log(mycat, LOG4C_PRIORITY_ERROR,
            "some error from app1 at line %d in file %s - loop ",
            __LINE__, __FILE__);

    if ( log4c_fini()){
        printf("log4c_fini() failed");
    }

    return 0;
}

/*[>* fatal <]	LOG4C_PRIORITY_FATAL	= 000, */
/*[>* alert <]	LOG4C_PRIORITY_ALERT	= 100, */
/*[>* crit <]	      	LOG4C_PRIORITY_CRIT	= 200, */
/*[>* error <]	LOG4C_PRIORITY_ERROR	= 300, */
/*[>* warn <]	      	LOG4C_PRIORITY_WARN	= 400, */
/*[>* notice <]	LOG4C_PRIORITY_NOTICE	= 500, */
/*[>* info <]	      	LOG4C_PRIORITY_INFO	= 600, */
/*[>* debug <]	LOG4C_PRIORITY_DEBUG	= 700,*/
/*[>* trace <]	LOG4C_PRIORITY_TRACE	= 800,*/
/*[>* notset <]	LOG4C_PRIORITY_NOTSET	= 900,*/
/*[>* unknown <]	LOG4C_PRIORITY_UNKNOWN	= 1000*/


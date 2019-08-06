/**
 *  -lglog
 */

#include <iostream>
#include <glog/logging.h>

int main(int argc, char** argv)
{
	google::InitGoogleLogging(argv[0]);
		/*	argv[0]: set the log file name
			<program name>.<hostname>.<user name>.log.<severity level>.<date>.<time>.<pid> */
	FLAGS_log_dir = "/tmp/";
    FLAGS_logtostderr = 1;
    FLAGS_minloglevel = 0;
    FLAGS_colorlogtostderr = 1;
    FLAGS_log_dir = "/tmp/";

	LOG(INFO) << "I am INFO";
	LOG(WARNING) << "I am WARNING!";
	LOG(ERROR) << "I am ERROR!";

	google::ShutdownGoogleLogging();
	return 0;
}

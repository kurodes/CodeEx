#include <iostream>
#include <glog/logging.h>

int main(int argc, char** argv)
{
        FLAGS_alsologtostderr = 1;
            FLAGS_log_dir = "/tmp/";
                google::InitGoogleLogging(argv[0]);
                        /*  argv[0]: set the log file name
                         *              <program name>.<hostname>.<user
                         *              name>.log.<severity
                         *              level>.<date>.<time>.<pid> */

                    LOG(INFO) << "I am INFO";
                    LOG(WARNING) << "I am WARNING!";
                    LOG(ERROR) << "I am ERROR!";
                    LOG(FATAL) << "I am FATAL!";
        return 0;
}


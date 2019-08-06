g++ -std=c++11 -g -Wall -lthrift TimeService.cpp WhatTime_types.cpp WhatTime_constants.cpp server.cpp -o server
g++ -std=c++11 -g -Wall -lthrift TimeService.cpp WhatTime_types.cpp WhatTime_constants.cpp client.cpp -o client

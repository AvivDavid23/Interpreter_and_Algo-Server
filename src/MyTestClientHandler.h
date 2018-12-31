//
// Created by aviv on 12/31/18.
//

#ifndef SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H
#define SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

/**
 * A type of Client Handler
 */
class MyTestClientHandler : public ClientHandler {
    Solver *solver;
    CacheManager *chcheManager;
public:
    void handleClient(std::istream inputStream, std::ostream outputStream);
};


#endif //SECONDYEARPROJECT_BIU_MYTESTCLIENTHANDLER_H

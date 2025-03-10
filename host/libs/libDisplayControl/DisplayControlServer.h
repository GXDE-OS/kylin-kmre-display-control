/*
* Copyright (C) 2011 The Android Open Source Project
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#ifndef _DISPLAY_CONTROL_SERVER_H
#define _DISPLAY_CONTROL_SERVER_H

#include "SocketStream.h"
#include "emugl/common/mutex.h"
#include "emugl/common/thread.h"

class DisplayControlServer : public emugl::Thread
{
public:
    static DisplayControlServer *create(const char* addr);
    virtual ~DisplayControlServer();

    virtual intptr_t main();

    bool isExiting() const { return m_exiting; }

private:
    DisplayControlServer();

private:
    emugl::Mutex m_lock;
    kmre::DisplayControl::SocketStream *m_listenSock;
    bool m_exiting;
};

#endif

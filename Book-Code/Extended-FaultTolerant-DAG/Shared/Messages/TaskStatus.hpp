/*
Copyright (c) 2015 James Dean Mathias

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef _TASKSTATUSMESSAGE_HPP_
#define _TASKSTATUSMESSAGE_HPP_

#include "MessagePBMixIn.hpp"

//
// Google Protocol Buffers cause hella warnings, ignore them
#pragma warning(push, 0)
#include "TaskStatus.pb.h"
#pragma warning(pop)

namespace Messages
{
	// -----------------------------------------------------------------
	//
	// @details This class is used to send the status of a task from
	// a compute server back to the client.
	//
	// -----------------------------------------------------------------
	class TaskStatus : public MessagePBMixIn<PBMessages::TaskStatus>
	{
	public:
		TaskStatus() :
			MessagePBMixIn(Messages::Type::TaskStatus)
		{
		}

		TaskStatus(uint64_t taskId, PBMessages::TaskStatus_Status status) :
			MessagePBMixIn(Messages::Type::TaskStatus)
		{
			m_message.set_taskid(taskId);
			m_message.set_status(status);
		}

		uint64_t getTaskId()						{ return m_message.taskid(); }
		PBMessages::TaskStatus_Status getStatus()	{ return m_message.status(); }
	};
}

#endif // _TASKSTATUSMESSAGE_HPP_

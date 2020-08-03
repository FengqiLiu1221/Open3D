// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2020 www.open3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#pragma once

#include "open3d/utility/ReceiverBase.h"

namespace open3d {
namespace utility {

/// Receiver implementation which always returns a successful status.
/// This class is meant for testing puproses.
class DummyReceiver : public open3d::utility::ReceiverBase {
public:
    DummyReceiver(const std::string& address, int timeout)
        : ReceiverBase(address, timeout) {}

    std::shared_ptr<zmq::message_t> CreateStatusOKMsg() {
        auto OK = messages::Status::OK();
        msgpack::sbuffer sbuf;
        messages::Reply reply{OK.MsgId()};
        msgpack::pack(sbuf, reply);
        msgpack::pack(sbuf, OK);
        return std::shared_ptr<zmq::message_t>(
                new zmq::message_t(sbuf.data(), sbuf.size()));
    }

    std::shared_ptr<zmq::message_t> ProcessMessage(
            const messages::Request& req,
            const messages::SetMeshData& msg,
            const msgpack::object& obj) override {
        return CreateStatusOKMsg();
    }
    std::shared_ptr<zmq::message_t> ProcessMessage(
            const messages::Request& req,
            const messages::GetMeshData& msg,
            const msgpack::object& obj) override {
        return CreateStatusOKMsg();
    }
    std::shared_ptr<zmq::message_t> ProcessMessage(
            const messages::Request& req,
            const messages::SetCameraData& msg,
            const msgpack::object& obj) override {
        return CreateStatusOKMsg();
    }
    std::shared_ptr<zmq::message_t> ProcessMessage(
            const messages::Request& req,
            const messages::SetProperties& msg,
            const msgpack::object& obj) override {
        return CreateStatusOKMsg();
    }
    std::shared_ptr<zmq::message_t> ProcessMessage(
            const messages::Request& req,
            const messages::SetActiveCamera& msg,
            const msgpack::object& obj) override {
        return CreateStatusOKMsg();
    }
    std::shared_ptr<zmq::message_t> ProcessMessage(
            const messages::Request& req,
            const messages::SetTime& msg,
            const msgpack::object& obj) override {
        return CreateStatusOKMsg();
    }
};

}  // namespace utility
}  // namespace open3d

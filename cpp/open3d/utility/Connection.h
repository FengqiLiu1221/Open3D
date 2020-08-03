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

#include <memory>
#include <zmq.hpp>

namespace open3d {
namespace utility {

class Connection {
public:
    Connection();

    /// Creates a Connection object used for sending data.
    /// \param address          The address of the receiving end.
    ///
    /// \param connect_timeout  The timeout for the connect operation of the
    /// socket.
    ///
    /// \param timeout          The timeout for sending data.
    ///
    Connection(const std::string& address, int connect_timeout, int timeout);
    ~Connection();

    /// Function for sending data wrapped in a zmq message object.
    std::shared_ptr<zmq::message_t> Send(zmq::message_t& send_msg);

private:
    std::unique_ptr<zmq::socket_t> socket_;
    const std::string address_;
    const int connect_timeout_;
    const int timeout_;
};
}  // namespace utility
}  // namespace open3d

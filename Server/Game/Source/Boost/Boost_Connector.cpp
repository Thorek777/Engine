#include "../../../Common/Include.hpp"

string Read(tcp::socket& socket)
{
    boost::asio::streambuf buf;
    boost::asio::read_until(socket, buf, "\n");
    string data = boost::asio::buffer_cast<const char*>(buf.data());
    return data;
}

void Send(tcp::socket& socket, const string& message)
{
    const string msg = message + "\n";
    boost::asio::write(socket, boost::asio::buffer(message));
}

int Boost_ExecuteConnect()
{
    boost::asio::io_service io_service;
    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 1234));
    tcp::socket socket(io_service);
    acceptor.accept(socket);
    string message = Read(socket);
    cout << message << endl;
    Send(socket, "Server has sent information to Client.");
    cout << "Server has sent information." << "\n";
    return 0;
}

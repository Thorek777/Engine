#include "../../../../Common/D_Includes.hpp"
#include "../../../../Common/O_Includes.hpp"

using namespace boost::asio;
using ip::tcp;

namespace Boost
{
	std::string Read(tcp::socket& socket)
	{
		boost::asio::streambuf buf;
		boost::asio::read_until(socket, buf, "\n");
		std::string data = boost::asio::buffer_cast<const char*>(buf.data());
		return data;
	}

	void Send(tcp::socket& socket, const std::string& message)
	{
		const std::string msg = message + "\n";
		boost::asio::write(socket, boost::asio::buffer(message));
	}

	int ExecuteConnect()
	{
		boost::asio::io_service io_service;
		tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 1234));
		tcp::socket socket(io_service);
		acceptor.accept(socket);
		std::string message = Read(socket);
		std::cout << message << std::endl;
		Send(socket, "Server has sent information to Client.");
		std::cout << "Server has sent information." << "\n";
		return 0;
	}
}

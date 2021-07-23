#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using namespace std;
using ip::tcp;

int main()
{
	boost::asio::io_service io_service;
	tcp::socket socket(io_service);
	socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));
	const string msg = "Client has sent information to Server. \n";
	boost::system::error_code error;
	boost::asio::write(socket, boost::asio::buffer(msg), error);

	if (!error)
		cout << "Client has sent information." << endl;
	else
		cout << "Client hasn't sent information.: " << error.message() << endl;

	boost::asio::streambuf receive_buffer;
	boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);

	if (error && error != boost::asio::error::eof)
		cout << "Receive failed: " << error.message() << endl;
	else
	{
		const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
		cout << data << endl;
	}

	system("pause");
	return 0;
}

import asio;
import std;
import mylib;


int main()
{
    asio::io_context ctx;
    ctx.run();
    mylib::f();
    mylib::g();
}
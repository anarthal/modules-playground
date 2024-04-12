import asio;
import std;

int main()
{
    static_assert(std::is_same_v<asio::any_io_executor, asio::executor>);
}
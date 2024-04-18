import charconv;
import std;


int main()
{
    char buff [512]{};
    auto [ptr, ec] = boost::charconv::to_chars(buff, buff+sizeof(buff), 4.2);
    std::cout << "size: " << (ptr-buff) << ", ec: " << std::make_error_code(ec) << std::endl;
    std::puts(buff);
}
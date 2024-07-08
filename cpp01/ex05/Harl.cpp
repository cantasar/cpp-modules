#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "XL-çift peynirli-üçlü turşu-özel-ketçaplı burgerime fazladan domuz pastır- ması yemeyi seviyorum. Gerçekten seviyorum!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "Ekstra domuz pastırması eklemenin daha fazla paraya mal olduğuna inanamıy- orum. Burgerime yeterince pastırma koymadınız! Yapsaydınız, daha fazlasını iste- mezdim!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "Bence bedavaya fazladan pastırma yemeyi hak ediyorum. Ben yıllardır geliyorum, sen geçen aydan beri burada çalışmaya başladın." << std::endl;
}

void Harl::error(void)
{
	std::cout << "Bu kabul edilemez! Şimdi müdürle konuşmak istiyorum." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    void (Harl::*comments[4])();

    comments[0] = &Harl::debug;
    comments[1] = &Harl::info;
    comments[2] = &Harl::warning;
    comments[3] = &Harl::error;

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
            (this->*comments[i])();
    }
}

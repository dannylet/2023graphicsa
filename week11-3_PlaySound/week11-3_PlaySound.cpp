#include<windows.h>

int main()
{
    PlaySound("do_re_mi\\do.wav", NULL, SND_SYNC);
    PlaySound("do_re_mi\\do.wav", NULL, SND_SYNC);
    PlaySound("do_re_mi\\do.wav", NULL, SND_SYNC);
    PlaySound("do_re_mi\\re.wav", NULL, SND_SYNC);
    PlaySound("do_re_mi\\mi.wav", NULL, SND_SYNC);
}

#include <stdio.h>

int main()
{
    char ciphertext[] = "f2/)+E='9E(+-/44/4-E:5E-+:E<+8?E:/8+*E5,E9/::/4-E(?E.+8E9/9:+8E54E:.+E('41QE'4*E5,E.'</4-E45:./4-E:5E*5_E54)+E58E:=/)+E9.+E.'*E6++6+*E/4:5E:.+E(551E.+8E9/9:+8E='9E8+'*/4-QE(;:E/:E.'*E45E6/):;8+9E58E)54<+89':/549E/4E/:QE&'4*E=.':E/9E:.+E;9+E5,E'E(551QLE:.5;-.:Ef2/)+E&=/:.5;:E6/):;8+9E58E)54<+89':/54dL";
    int i = 0;
    int key = 0;
    for (key = 1; key < 26; ++key) {
        for (i = 0; ciphertext[i] != 0; ++i) {
            ciphertext[i] += key;
        }
        printf("%s \n", ciphertext);
    }

    return 0;
}

#ifndef INDICATORS_H
#define INDICATORS_H

class Indicators {
public:
    static int run();

private:
    static int str_len(char s[]);
    static int lwr_str_cnt(char s[]);
    static int upr_str_cnt(char s[]);
    static int dgt_str_cnt(char s[]);
    static int nalpha_str_cnt(char s[]);
    static int chr_str_cnt(char c, char s[] );
    static char* chr_str_pos(char c, char s[] );
    static char* chr_str_rpos(char c, char s[] );
    static char* str_rev(char s[]);
    static int str_word_count(char s[]);
};

#endif //INDICATORS_H

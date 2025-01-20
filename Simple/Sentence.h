#ifndef SENTENCE_H
#define SENTENCE_H

class Sentence {
public:
    static int run();

private:
    static int str_len(char s[]);
    static int lwr_str_cnt(char s[]);
    static int upr_str_cnt(char s[]);
    static int dgt_str_cnt(char s[]);
    static int nalpha_str_cnt(char s[]);
    static int chr_str_cnt(char c, char s[] );
    static int chr_str_pos(char c, char s[] );
    static int chr_str_rpos(char c, char s[] );
    static void str_rev(char s[]);
};

#endif //SENTENCE_H

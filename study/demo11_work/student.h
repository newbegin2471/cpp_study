#ifndef __STUDENT_H__
#define __STUDENT_H__
class StuInfo{
    private:
        double  *score;
        int num;
    public:
        void init();
        void setNum(int n);
        void input();
        void sort();
        void show();
        void freeScore();
};

#endif
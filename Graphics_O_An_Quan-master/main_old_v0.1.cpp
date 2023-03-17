#include <graphics.h>
#include <conio.h>

#define MAXX 800
#define MAXY 550
#define BGC 0
#define ARC 15

struct ToaDoDan {
    int x;
    int y;
};

ToaDoDan tdd[] = {{0, 0}, {0, 0}, {-25, -25}, {25, -25}, {-25, 25}, {25, 25}, {0, -25}, {-25, 0}, {25, 0}, {0, 25}, {-12, -12}, {12, -12}, {-12, 12}, {12, 12}, {-12, -25}, {12, -25}, {-12, 25}, {12, 25}, {-25, -12}, {25, -12}, {-25, 12}, {25, 12}};
ToaDoDan tddq[] = {{0, 0}, {35, -75}, {35, -60}, {35, -45}, {35, -30}, {35, -15}, {35, 0}, {35, 15}, {35, 30}, {35, 45}, {35, 60}, {35, 75}, {20, -75}, {20, -60}, {20, -45}, {20, -30}, {20, -15}, {20, 0}, {20, 15}, {20, 30}, {20, 45}, {20, 60}, {20, 75}};

int HienTai = 0, DaiDan = 0;
char TxtPlayer10[] = "Player 1: 0";
char TxtPlayer20[] = "Player 2: 0";
int Abs(int x) {
    return x > 0 ? x : -x;
}

void VeDan(int soO, int soDan) {
    int n = (7 - Abs(6 - soO)) * 100;
    int m = (soO / 6 + 2) * 100;
    circle(n + tdd[soDan].x, m + tdd[soDan].y, 3);
}

void VeQuan(int soO) {
    int n = (soO + 1) * 100;
    rectangle(n - 10, 230, n + 10, 270);
}

void VeBan() {
    rectangle(150, 150, 650, 350);
    for (int i = 1; i <= 4; i++)
        line(150 + 100 * i, 150, 150 + 100 * i, 350);
    line(150, 250, 650, 250);
    arc(150, 250, 90, 270, 100);
    arc(650, 250, -90, 90, 100);
    for (int i = 0; i < 12; i++) {
        if (i % 6) {
            for (int j = 1; j <= 5; j++)
                VeDan(i, j);
        } else
            VeQuan(i);
    }
}

void XoaO() {
    int n = (7 - Abs(6 - HienTai)) * 100;
    int m = (HienTai / 6 + 2) * 100;
    setfillstyle(1, BGC);
    bar(n - 49, m - 49, n + 50, m + 50);
}

void XoaOQuan() {
    setfillstyle(1, BGC);
    setcolor(BGC);
    if (HienTai == 0)
        pieslice(147, 250, 90, 270, 95);
    else
        pieslice(653, 250, -90, 90, 95);
}

void VeMuiTen() {
    int n = (7 - Abs(6 - HienTai)) * 100;
    int m = (HienTai / 6) * 300 + 100;
    setcolor(ARC);
    line(n, m - 20, n, m + 20);
}

void XoaMuiTen() {
    int n = (7 - Abs(6 - HienTai)) * 100;
    int m = (HienTai / 6) * 300 + 100;
    setcolor(BGC);
    line(n, m - 20, n, m + 20);
}

void ChonO() {
    int n = (7 - Abs(6 - HienTai)) * 100;
    int m = (HienTai / 6 + 2) * 100;
    setcolor(3);
    rectangle(n - 48, m - 48, n + 48, m + 48);
}

void BoChonO() {
    int n = (7 - Abs(6 - HienTai)) * 100;
    int m = (HienTai / 6 + 2) * 100;
    setcolor(BGC);
    rectangle(n - 48, m - 48, n + 48, m + 48);
}

class OAnQuan {
  private:
  public:
    OAnQuan() {
        conQuan = 1;
        soDan = 5;
    }
    int conQuan;
    int soDan;
    void veDan();
};

void OAnQuan::veDan() {
    int n, m;
    if (HienTai % 6 == 0) {
        n = (HienTai + 1) * 100;
        circle(n + (1 - HienTai / 3) * tddq[this->soDan].x, 250 + tddq[this->soDan].y, 3);
    } else {
        int n = (7 - Abs(6 - HienTai)) * 100;
        int m = (HienTai / 6 + 2) * 100;
        circle(n + tdd[this->soDan].x, m + tdd[this->soDan].y, 3);
    }
}

int main() {
    initwindow(MAXX + 9, MAXY + 13);
    OAnQuan oaq[12];
    char c, text[10];
    int Player = 0, tmp;
    int Score[2] = {0, 0};
    settextstyle(0, 0, 3);
    outtextxy(100, 40, TxtPlayer10);
    outtextxy(100, 440, TxtPlayer20);
    int mx;
    for (int i = 0; i < 12; i++)
        if (i % 6 == 0)
            oaq[i].soDan = 0;
    VeBan();
    HienTai = 1;
    while (true) {
        VeMuiTen();
        do {
            c = getch();
            switch (c) {
            case 75:
                XoaMuiTen();
                do {
                    HienTai -= (1 - 2 * Player);
                    if (HienTai == Player * 12)
                        HienTai = Player * 2 + 5;
                } while (oaq[HienTai].soDan == 0);
                VeMuiTen();
                break;
            case 77:
                XoaMuiTen();
                do {
                    HienTai += (1 - 2 * Player);
                    if (HienTai == 6)
                        HienTai = Player * 10 + 1;
                } while (oaq[HienTai].soDan == 0);
                VeMuiTen();
                break;
            }
        } while (c != 13);
        ChonO();
        //c=getch();
        do {
            c = getch();
            switch (c) {
            case 75:
                mx = Player * 2 - 1;
                break;
            case 77:
                mx = 1 - Player * 2;
                break;
            }
        } while (c != 75 && c != 77);
        XoaMuiTen();
        setcolor(15);
        DaiDan = oaq[HienTai].soDan;
        oaq[HienTai].soDan = 0;
        XoaO();
        while (true) {
            delay(400);
            if (DaiDan == 0) {
                HienTai += mx;
                if (HienTai == 12)
                    HienTai = 0;
                else if (HienTai == -1)
                    HienTai = 11;
                if (HienTai % 6) {
                    XoaO();
                    DaiDan = oaq[HienTai].soDan;
                    if (DaiDan == 0) {
                        do {
                            HienTai += mx;
                            if (HienTai == 12)
                                HienTai = 0;
                            else if (HienTai == -1)
                                HienTai = 11;
                            if (HienTai % 6 == 0) {
                                if (oaq[HienTai].conQuan) {
                                    if (oaq[HienTai].soDan >= 5) {
                                        Score[Player] += (oaq[HienTai].soDan + 10);
                                        setcolor(15);
                                        sprintf(text, "Player %d: %d", Player + 1, Score[Player]);
                                        outtextxy(100, 40 + Player * 400, text);
                                        oaq[HienTai].soDan = 0;
                                        oaq[HienTai].conQuan = 0;
                                        XoaOQuan();
                                        if ((oaq[6 - HienTai].soDan == oaq[6 - HienTai].conQuan) && (oaq[6 - HienTai].conQuan == 0)) {
                                            for (int i = 1; i < 6; i++)
                                                Score[0] += oaq[i].soDan;
                                            for (int i = 7; i < 12; i++)
                                                Score[1] += oaq[i].soDan;
                                            cleardevice();
                                            setcolor(15);
                                            sprintf(text, "Player %d: %d", 1, Score[0]);
                                            outtextxy(100, 150, text);
                                            sprintf(text, "Player %d: %d", 2, Score[1]);
                                            outtextxy(100, 250, text);
                                            sprintf(text, "Winner: Player %d", Score[0] > Score[1] ? 1 : 2);
                                            outtextxy(100, 350, text);
                                            getch();
                                            return 0;
                                        }
                                    } else
                                        break;
                                } else if (oaq[HienTai].soDan > 0) {
                                    Score[Player] += oaq[HienTai].soDan;
                                    setcolor(15);
                                    sprintf(text, "Player %d: %d", Player + 1, Score[Player]);
                                    outtextxy(100, 40 + Player * 400, text);
                                    oaq[HienTai].soDan = 0;
                                    XoaOQuan();
                                    if ((oaq[6 - HienTai].soDan == oaq[6 - HienTai].conQuan) && (oaq[6 - HienTai].conQuan == 0)) {
                                        for (int i = 1; i < 6; i++)
                                            Score[0] += oaq[i].soDan;
                                        for (int i = 7; i < 12; i++)
                                            Score[1] += oaq[i].soDan;
                                        cleardevice();
                                        setcolor(15);
                                        sprintf(text, "Player %d: %d", 1, Score[0]);
                                        outtextxy(100, 150, text);
                                        sprintf(text, "Player %d: %d", 2, Score[1]);
                                        outtextxy(100, 250, text);
                                        sprintf(text, "Winner: Player %d", Score[0] > Score[1] ? 1 : 2);
                                        outtextxy(100, 350, text);
                                        getch();
                                        return 0;
                                    }
                                } else
                                    break;
                            } else if (oaq[HienTai].soDan > 0) {
                                Score[Player] += oaq[HienTai].soDan;
                                setcolor(15);
                                sprintf(text, "Player %d: %d", Player + 1, Score[Player]);
                                outtextxy(100, 40 + Player * 400, text);
                                oaq[HienTai].soDan = 0;
                                XoaO();
                            } else
                                break;
                            HienTai += mx;
                            if (HienTai == 12)
                                HienTai = 0;
                            else if (HienTai == -1)
                                HienTai = 11;
                            DaiDan = oaq[HienTai].soDan;
                            delay(400);
                        } while (DaiDan == 0);
                        break;
                    }
                    oaq[HienTai].soDan = 0;
                    delay(400);
                } else
                    break;
            }
            DaiDan--;
            HienTai += mx;
            if (HienTai == 12)
                HienTai = 0;
            else if (HienTai == -1)
                HienTai = 11;
            oaq[HienTai].soDan++;
            oaq[HienTai].veDan();
        }
        Player = 1 - Player;
        tmp = 1;
        do {
            HienTai = 6 * Player + tmp;
            tmp++;
        } while (oaq[HienTai].soDan == 0 && tmp <= 5);
        if (oaq[HienTai].soDan == 0) {
            Score[Player] -= 5;
            setcolor(15);
            sprintf(text, "Player %d: %d", Player + 1, Score[Player]);
            outtextxy(100, 40 + Player * 400, text);
            for (int i = 1 + 6 * Player; i < 6 + 6 * Player; i++) {
                VeDan(i, 1);
                oaq[i].soDan = 1;
            }
        }
    }
    getch();
    closegraph();
    return 0;
}

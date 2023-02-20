#include <iostream>
#include <fstream>

int main() {
    int dept[5][5];
    int prog[5][5];
    int deptAssigned[5] = {-1, -1, -1, -1, -1};
    int deptPref, progPref;

    int deptMatches[5] = {};

    int count = 0;
    int assign;
    int h, i, j, k;

    std::ifstream infile("matching-data.txt");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 5; j++) {
            infile >> (i < 5 ? dept[j][i] : prog[j][i - 5]);
        }
    }
    infile.close();

    for (h = 1; h < 6; h++) {
        int progNum[5][3];
        int topDept[3] = {-1, -1, -1};
        for (i = 0; i < 5; i++) {
            deptPref = 0;
            assign = 0;
            for (j = 0; j < 5; j++) {
                if (dept[i][j] >= h) {
                    if (dept[i][j] == h) {
                        progPref = 0;
                        for (k = 0; k < 5; k++) {
                            if (prog[h-1][k] == i + 1) {
                                progPref = k;
                            }
                            if (deptAssigned[k] == i) {
                                assign = 1;
                            }
                        }
                        if (assign == 0 && (topDept[0] == -1 || (topDept[1] > deptPref) || (topDept[1] == deptPref && topDept[2] > progPref))) {
                            topDept[0] = i;
                            topDept[1] = deptPref;
                            topDept[2] = progPref;
                        }
                    }
                    deptPref++;
                }
            }
        }
        deptAssigned[count] = topDept[0];
        count++;
        deptMatches[topDept[0]] = h;
    }
    for (i = 0; i < 5; i++) {
        std::cout << "Department #" << i+1 << " will get Programmer #" << deptMatches[i] << std::endl;
    }
    return 0;
}

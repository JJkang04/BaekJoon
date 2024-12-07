    #include <iostream>
    #include <string>
    using namespace std;

    int countTime(int startH, int startM, int endH, int endM, int targetDigit) {
        int count = 0;

        int startTime = 60 * startH + startM;
        int endTime = 60 * endH + endM;

        for(int currentTime = startTime; currentTime <= endTime; currentTime++) {
            int hour = currentTime / 60;
            int minute = currentTime % 60;

            string timeString = (hour<10 ? "0" : "") + to_string(hour) + (minute<10 ? "0" : "") + to_string(minute);

            if(timeString.find(to_string(targetDigit)) != string::npos) count++;
        }

        return count;
    }
    int main() {

        int start_H, start_M, end_H, end_M, n;
        cin >> start_H >> start_M >> end_H >> end_M >> n;

        cout << countTime(start_H, start_M, end_H, end_M, n) << endl;
        
        return 0;
    }
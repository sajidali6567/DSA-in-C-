class Solution {
public:
    /*   0- north
     *   1- east
     *   2- south
     *   3- west
    */
    bool isRobotBounded(string instructions) {
        int posx = 0, posy = 0, dir = 0;
        for(auto ch:instructions) {
            switch(ch) {
                case 'G':
                    switch(dir) {
                        case 0:
                            posy++; break;
                        case 1:
                            posx++; break;
                        case 2:
                            posy--; break;
                        case 3:
                            posx--; break;
                    }
                    break;
                case 'L':
                    dir = (dir-1+4)%4; break;
                case 'R':
                    dir = (dir+1)%4; break;
            }
        }
        // There will be cycle when it returns to origin or position and direction both changes
        if(posx == 0 && posy == 0) return true;
        if(dir!=0) return true;
        return false;
    }
};
/*
134. Gas Station
Medium

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique
*/
// Approach
// In the question given that
// If there exists a solution, it is guaranteed to be unique
// -This lines clearly tells us that we have unique or no solution exists

// Here two cases are possible

// if our total_gas is less than our total cost in that case we can't complete our journey ,so will return -1
// Now we have a unique solution that means single starting_point exists
// To find that point we will keep track of my current_gas+=gas[i]-cost[i]
// lets suppose at any index our current gas became negative so we can clearly say that till that index all the gas station between ith and starting point are bad, starting point as well.
// So, this means we can start trying at next gas_station on the i+1 station

// Solution codehelp [TC: O(n) & SC: O(1)]
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0; int totalCost=0;
        int startingPoint=0; int currGas=0;
        for(int i=0;i<gas.size();i++){
            totalGas+=gas[i];
            totalCost+=cost[i];
            currGas+= gas[i] - cost[i];
            if(currGas<0){
                startingPoint = i+1;
                currGas = 0;
            }
        }
        if(totalGas<totalCost)
        return -1;
        return startingPoint;
    }
};





//Solution 2
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0; int totalCost=0;
        int startingPoint=0; int currGas=0;
        for(int i=0;i<gas.size();i++){
            totalGas+=gas[i];
            totalCost+=cost[i];
            currGas+= gas[i] - cost[i];
            if(currGas<0){
                startingPoint = i+1;
                currGas = 0;
            }
        }
        if(totalGas<totalCost)
        return -1;
        return startingPoint;
    }
};

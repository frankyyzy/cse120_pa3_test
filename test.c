#define Main UselessMain
#include "pa3d.c"
#undef Main

/* 
 * Author: Frank Ye 
 * Date: Feb 12th 2020
 *
 * DISCLAIMER: 
 * The test cases used here are from discussion slides. They will in the great 
 * majority of cases, accurately detect the presence or absence of bugs and 
 * design flaws.
 *
 * However, by no means is this a complete test suite for this pa. 
 *
 * Happy coding. 
 *
 * Cheers. 
 *
 */

/*
 * test1,2,3,4 may have different orders based on implementation and scheduler
 * However, test5 has to be this order !!!
 *
 */
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();

void Main(int c, char **argv)
{
    InitRoad();
    void (*tests[9])() = {test1, test2, test3, test4, test5, test6, test7, test8, test9};
    (*tests[atoi(argv[1]) - 1])();
}

void test1()
{

    DPrintf("Test 1: correct order should be 1 2 5 3 4\n");
    if (Fork() == 0)
    {
        Delay(10);
        driveRoad(EAST, 40);
        Exit();
    }
    if (Fork() == 0)
    {
        Delay(30);
        driveRoad(EAST, 40);
        Exit();
    }
    if (Fork() == 0)
    {
        Delay(40);
        driveRoad(EAST, 40);
        Exit();
    }
    if (Fork() == 0)
    {
        Delay(20);
        driveRoad(WEST, 40);
        Exit();
    }

    driveRoad(WEST, 40);
    Exit();
}

void test2()
{
    DPrintf("Test 2: correct order should be 1 2 3 4\n");
    if (Fork() == 0)
    {
        Delay(10);
        driveRoad(EAST, 40);
        Exit();
    }
    if (Fork() == 0)
    {
        Delay(20);
        driveRoad(EAST, 40);
        Exit();
    }
    if (Fork() == 0)
    {
        Delay(30);
        driveRoad(EAST, 40);
        Exit();
    }

    driveRoad(WEST, 40);
    Exit();
}

void test3()
{
    DPrintf("Test 3: correct order should be 1 2 5 3 4\n");

    if (Fork() == 0)
    {
        Delay(100);
        driveRoad(EAST, 10);
        Exit();
    }
    if (Fork() == 0)
    {
        Delay(200);
        driveRoad(EAST, 40);
        Exit();
    }
    if (Fork() == 0)
    {
        Delay(300);
        driveRoad(EAST, 40);
        Exit();
    }
    if (Fork() == 0)
    {
        Delay(900);
        driveRoad(WEST, 40);
        Exit();
    }
    driveRoad(WEST, 40);
    Exit();
}

//1 3 2 4 6 5 7
void test4()
{
    DPrintf(" Test 4: correct order: 1 3 2 4 6 5 7\n");

    if (Fork() == 0)
    {
        Delay(800);
        driveRoad(WEST, 40);
        Exit();
    }
    if (Fork() == 0)
    {
        Delay(500);
        driveRoad(EAST, 40);
        Exit();
    }
    if (Fork() == 0)
    {
        Delay(550);
        driveRoad(EAST, 40);
        Exit();
    }
    if (Fork() == 0)
    {
        Delay(600);
        driveRoad(EAST, 40);
        Exit();
    }

    if (Fork() == 0)
    {
        Delay(1000);
        driveRoad(WEST, 40);
        Exit();
    }

    if (Fork() == 0)
    {
        Delay(1100);
        driveRoad(WEST, 40);
        Exit();
    }
    driveRoad(WEST, 40);
    Exit();
}

void test5()
{
    DPrintf("Test 5: A hard one to solve!!\n Correct order should be 1 3 2\n");

    if (Fork() == 0)
    { // car 2
        Delay(100);
        driveRoad(WEST, 10);
        Exit();
    }

    if (Fork() == 0)
    { // car 3
        Delay(200);
        driveRoad(EAST, 60);
        Exit();
    }

    driveRoad(WEST, 10); // car 1
    //it would take car 1 360 seconds to get to position 2
    Exit();
}
/*https://piazza.com/class/k51m7y75yswei?cid=414*/
void test6()
{
    DPrintf("Test 6\n");

    if (Fork() == 0)
    { // car 2
        driveRoad(WEST, 60);
        Exit();
    }

    if (Fork() == 0)
    { // car 3
        driveRoad(WEST, 60);
        Exit();
    }

    if (Fork() == 0)
    { // car 4
        driveRoad(WEST, 60);
        Exit();
    }

    if (Fork() == 0)
    { // car 5
        driveRoad(WEST, 60);
        Exit();
    }

    if (Fork() == 0)
    { // car 6
        driveRoad(EAST, 60);
        Exit();
    }

    if (Fork() == 0)
    { // car 7
        driveRoad(EAST, 60);
        Exit();
    }

    if (Fork() == 0)
    { // car 8
        driveRoad(EAST, 60);
        Exit();
    }
    if (Fork() == 0)
    { // car 9
        driveRoad(EAST, 60);
        Exit();
    }

    if (Fork() == 0)
    { // car 10
        driveRoad(EAST, 60);
        Exit();
    }

    // car 1
    driveRoad(WEST, 60);
    Exit();
}

void test7()
{
    DPrintf("Test 7\n");
    if (Fork() == 0)
    {
        driveRoad(EAST, 60);
        Exit();
    }

    if (Fork() == 0)
    {
        driveRoad(EAST, 50);
        Exit();
    }

    if (Fork() == 0)
    {
        driveRoad(EAST, 30);
        Exit();
    }

    if (Fork() == 0)
    {
        Delay(40);
        driveRoad(WEST, 30);
        Exit();
    }

    driveRoad(EAST, 40);
    Exit();
}

/*https://piazza.com/class/k51m7y75yswei?cid=461*/
void test8()
{
    DPrintf("Test 8. Car 2 should not be the last one to enter\n");
    if (Fork() == 0)
    { // car 2
        Delay(1000);
        driveRoad(WEST, 60);
        Exit();
    }

    if (Fork() == 0)
    { //car 3
        driveRoad(EAST, 50);
        Exit();
    }

    if (Fork() == 0)
    { // car 4
        driveRoad(EAST, 30);
        Exit();
    }

    if (Fork() == 0)
    { // car 5
        driveRoad(EAST, 30);
        Exit();
    }

    driveRoad(WEST, 40); // car 1
}

void test9()
{
    DPrintf("Test 9. Car 2 should not be the last one to enter\n");
    if (Fork() == 0)
    { // car 2
        Delay(1000);
        driveRoad(EAST, 60);
        Exit();
    }
    if (Fork() == 0)
    { //car 3
        Delay(10);
        driveRoad(WEST, 40);
        Exit();
    }
    if (Fork() == 0)
    { //car 4
        Delay(10);
        driveRoad(WEST, 40);
        Exit();
    }
    if (Fork() == 0)
    { //car 5
        Delay(10);
        driveRoad(WEST, 40);
        Exit();
    }
    if (Fork() == 0)
    { //car 6
        Delay(10);
        driveRoad(WEST, 40);
        Exit();
    }

    driveRoad(EAST, 40); // car 1
    Exit();
}
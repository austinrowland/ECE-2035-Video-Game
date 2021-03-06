#include "graphics.h"

#include "globals.h"

/*
In this file put all your graphical functions (don't forget to declare them first
in graphics.h). So when you want to draw something use this file. One cool function
to look at would be uLCD.blit() there are more like filled_rectangle etc... 
https://os.mbed.com/users/4180_1/notebook/ulcd-144-g2-128-by-128-color-lcd/
This website is a good resource.
*/

// Sprite Declarations

static uint32_t Player_arr[121] = {
    0, 0, 16727552, 0, 0, 0, 0, 0, 16727552, 0, 0, 0, 0, 16727552, 16727552, 16727552, 
    16727552, 16727552, 16727552, 16727552, 0, 0, 0, 0, 0, 16727552, 0, 16727552, 0, 
    16727552, 0, 0, 0, 0, 0, 0, 16727552, 16727552, 16727552, 16727552, 16727552, 0, 
    0, 0, 0, 16727552, 0, 0, 16727552, 0, 16727552, 0, 0, 16727552, 0, 0, 16727552, 16727552, 
    16727552, 16727552, 16727552, 16727552, 16727552, 16727552, 16727552, 0, 0, 0, 0, 
    0, 16727552, 16727552, 16727552, 0, 0, 0, 0, 0, 0, 0, 16727552, 16727552, 16727552, 
    16727552, 16727552, 0, 0, 0, 0, 0, 0, 16727552, 16727552, 0, 16727552, 16727552, 
    0, 0, 0, 0, 0, 0, 16727552, 16727552, 0, 16727552, 16727552, 0, 0, 0, 0, 0, 16727552, 
    16727552, 16727552, 0, 16727552, 16727552, 16727552, 0, 0};

static int* Player = (int*)Player_arr;

static uint32_t PortalSprite_arr[121] = {
    1441536, 9437439, 9437439, 9437439, 9437439, 9437439, 9437439, 9437439, 9437439, 
    9437439, 9437439, 1441536, 9437439, 1441536, 1441536, 1441536, 1441536, 1441536, 
    1441536, 1441536, 1441536, 1441536, 1441536, 9437439, 1441536, 9437439, 9437439, 
    9437439, 9437439, 9437439, 9437439, 9437439, 1441536, 1441536, 9437439, 1441536, 
    9437439, 1441536, 1441536, 1441536, 1441536, 1441536, 9437439, 1441536, 1441536, 
    9437439, 1441536, 9437439, 1441536, 9437439, 9437439, 9437439, 1441536, 9437439, 
    1441536, 1441536, 9437439, 1441536, 9437439, 1441536, 9437439, 1441536, 9437439, 
    1441536, 9437439, 1441536, 1441536, 9437439, 1441536, 9437439, 1441536, 1441536, 
    1441536, 9437439, 1441536, 9437439, 1441536, 1441536, 9437439, 1441536, 9437439, 
    9437439, 9437439, 9437439, 9437439, 1441536, 9437439, 1441536, 1441536, 9437439, 
    1441536, 1441536, 1441536, 1441536, 1441536, 1441536, 1441536, 9437439, 1441536, 
    1441536, 9437439, 9437439, 9437439, 9437439, 9437439, 9437439, 9437439, 9437439, 
    9437439, 1441536, 1441536, 1441536, 1441536, 1441536, 1441536, 1441536, 1441536, 
    1441536, 1441536, 1441536, 1441536};

static int* PortalSprite = (int*)PortalSprite_arr;

static uint32_t Boss1_arr[121] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10223871, 10223871, 10223871, 10223871, 
    10223871, 0, 0, 0, 0, 0, 10223871, 10223871, 10223871, 10223871, 10223871, 10223871, 
    10223871, 0, 0, 0, 0, 10223871, 10223871, 14229536, 10223871, 14229536, 10223871, 
    10223871, 0, 0, 0, 0, 10223871, 10223871, 10223871, 10223871, 10223871, 10223871, 
    10223871, 0, 0, 0, 0, 10223871, 10223871, 14229536, 14229536, 14229536, 10223871, 
    10223871, 0, 0, 0, 0, 10223871, 14229536, 14229536, 14229536, 14229536, 14229536, 
    10223871, 0, 0, 0, 0, 10223871, 10223871, 10223871, 10223871, 10223871, 10223871, 
    10223871, 0, 0, 0, 0, 10223871, 0, 10223871, 0, 10223871, 0, 10223871, 0, 0, 0, 0, 
    10223871, 0, 10223871, 0, 10223871, 0, 10223871, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0};

static int* Boss1 = (int*)Boss1_arr;

static uint32_t NPC1_arr[121] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5431498, 5431498, 5431498, 5431498, 5431498, 
    0, 0, 0, 0, 0, 5431498, 5431498, 5431498, 5431498, 5431498, 5431498, 5431498, 0, 
    0, 0, 0, 5431498, 5431498, 14736347, 5431498, 14736347, 5431498, 5431498, 0, 0, 0, 
    0, 5431498, 5431498, 5431498, 5431498, 5431498, 5431498, 5431498, 0, 0, 0, 0, 5431498, 
    14736347, 5431498, 5431498, 5431498, 14736347, 5431498, 0, 0, 0, 0, 5431498, 5431498, 
    14736347, 14736347, 14736347, 5431498, 5431498, 0, 0, 0, 0, 5431498, 5431498, 5431498, 
    5431498, 5431498, 5431498, 5431498, 0, 0, 0, 0, 5431498, 0, 5431498, 0, 5431498, 
    0, 5431498, 0, 0, 0, 0, 5431498, 0, 5431498, 0, 5431498, 0, 5431498, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0};

static int* NPC1 = (int*)NPC1_arr;

static uint32_t bluePill_arr[121] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 590079, 590079, 590079, 590079, 590079, 590079, 590079, 0, 
    0, 0, 590079, 590079, 590079, 590079, 590079, 590079, 590079, 590079, 590079, 0, 
    0, 590079, 590079, 590079, 590079, 590079, 590079, 590079, 590079, 590079, 0, 0, 
    0, 590079, 590079, 590079, 590079, 590079, 590079, 590079, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static int* bluePill = (int*)bluePill_arr;

static uint32_t redPill_arr[121] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 16711680, 16711680, 16711680, 16711680, 16711680, 16711680, 
    16711680, 0, 0, 0, 16711680, 16711680, 16711680, 16711680, 16711680, 16711680, 16711680, 
    16711680, 16711680, 0, 0, 16711680, 16711680, 16711680, 16711680, 16711680, 16711680, 
    16711680, 16711680, 16711680, 0, 0, 0, 16711680, 16711680, 16711680, 16711680, 16711680, 
    16711680, 16711680, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static int* redPill = (int*)redPill_arr;

static uint32_t keySprite_arr[121] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 14733685, 14733685, 0, 0, 0, 0, 0, 0, 0, 0, 14733685, 0, 
    0, 14733685, 14733685, 14733685, 14733685, 14733685, 14733685, 0, 0, 14733685, 0, 
    0, 14733685, 0, 14733685, 0, 14733685, 0, 0, 0, 0, 14733685, 14733685, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static int* keySprite = (int*)keySprite_arr;

static uint32_t unopenedChest_arr[121] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 15579699, 15579699, 15579699, 15579699, 15579699, 15579699, 
    15579699, 0, 0, 0, 15579699, 15579699, 15579699, 15579699, 15579699, 15579699, 15579699, 
    15579699, 15579699, 0, 0, 10515973, 10515973, 10515973, 10515973, 16777215, 10515973, 
    10515973, 10515973, 10515973, 0, 0, 15579699, 15579699, 15579699, 15579699, 15579699, 
    15579699, 15579699, 15579699, 15579699, 0, 0, 15579699, 15579699, 15579699, 15579699, 
    15579699, 15579699, 15579699, 15579699, 15579699, 0, 0, 15579699, 15579699, 15579699, 
    15579699, 15579699, 15579699, 15579699, 15579699, 15579699, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static int* unopenedChest = (int*)unopenedChest_arr;

static uint32_t openedChest_arr[121] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15579699, 15579699, 
    15579699, 15579699, 16777215, 15579699, 15579699, 15579699, 15579699, 0, 0, 15579699, 
    15579699, 15579699, 15579699, 15579699, 15579699, 15579699, 15579699, 15579699, 0, 
    0, 15579699, 15579699, 15579699, 15579699, 15579699, 15579699, 15579699, 15579699, 
    15579699, 0, 0, 10515973, 10515973, 10515973, 10515973, 10515973, 10515973, 10515973, 
    10515973, 10515973, 0, 0, 15579699, 0, 0, 0, 0, 0, 0, 0, 15579699, 0, 0, 15579699, 
    0, 0, 0, 0, 0, 0, 0, 15579699, 0, 0, 15579699, 15579699, 15579699, 15579699, 15579699, 
    15579699, 15579699, 15579699, 15579699, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0};

static int* openedChest = (int*)openedChest_arr;

static uint32_t speechBubble_arr[121] = {
    0, 0, 6118749, 6118749, 6118749, 6118749, 6118749, 6118749, 6118749, 0, 0, 0, 6118749, 
    6118749, 16777215, 16777215, 16777215, 16777215, 16777215, 6118749, 6118749, 0, 0, 
    6118749, 16777215, 16777215, 16777215, 16777215, 16777215, 16777215, 16777215, 6118749, 
    0, 0, 6118749, 16777215, 0, 16777215, 0, 16777215, 0, 16777215, 6118749, 0, 0, 6118749, 
    16777215, 16777215, 16777215, 16777215, 16777215, 16777215, 16777215, 6118749, 0, 
    0, 6118749, 6118749, 16777215, 16777215, 16777215, 16777215, 16777215, 6118749, 6118749, 
    0, 0, 0, 6118749, 6118749, 16777215, 16777215, 6118749, 6118749, 6118749, 0, 0, 0, 
    0, 0, 6118749, 16777215, 16777215, 16777215, 6118749, 0, 0, 0, 0, 0, 0, 6118749, 
    6118749, 16777215, 16777215, 6118749, 0, 0, 0, 0, 0, 0, 0, 6118749, 6118749, 6118749, 
    6118749, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static int* speechBubble = (int*)speechBubble_arr;

static uint32_t tree_arr[121] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 249092, 249092, 249092, 249092, 249092, 
    0, 0, 0, 0, 0, 249092, 249092, 2351140, 249092, 2351140, 2351140, 249092, 0, 0, 0, 
    0, 249092, 2351140, 249092, 2351140, 249092, 2351140, 249092, 0, 0, 0, 0, 249092, 
    2351140, 2351140, 249092, 2351140, 249092, 249092, 0, 0, 0, 0, 0, 249092, 249092, 
    249092, 249092, 249092, 0, 0, 0, 0, 0, 0, 0, 15708741, 15708741, 13998383, 0, 0, 
    0, 0, 0, 0, 0, 0, 15708741, 15708741, 13998383, 0, 0, 0, 0, 0, 0, 0, 0, 15708741, 
    13998383, 15708741, 0, 0, 0, 0, 0, 0, 0, 0, 15708741, 13998383, 15708741, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static int* tree = (int*)tree_arr;

static uint32_t rock_arr[121] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 7236973, 7236973, 7236973, 7236973, 7236973, 0, 0, 0, 
    0, 0, 7236973, 7236973, 8490113, 8490113, 8490113, 7236973, 7236973, 0, 0, 0, 7236973, 
    7236973, 8490113, 8490113, 8490113, 8490113, 8490113, 7236973, 7236973, 0, 0, 7236973, 
    8490113, 8490113, 7236973, 8490113, 8490113, 7236973, 8490113, 7236973, 0, 0, 7236973, 
    8490113, 8490113, 8490113, 7236973, 7236973, 8490113, 8490113, 7236973, 0, 0, 7236973, 
    7236973, 8490113, 8490113, 8490113, 8490113, 8490113, 7236973, 7236973, 0, 0, 0, 
    7236973, 7236973, 7236973, 7236973, 7236973, 7236973, 7236973, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0};

static int* rock = (int*)rock_arr;

static uint32_t sword_arr[121] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5503705, 5503705, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    5503705, 5503705, 5503705, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5503705, 5503705, 5503705, 
    0, 6841958, 0, 0, 0, 0, 0, 0, 0, 5503705, 5503705, 5503705, 6841958, 0, 0, 0, 0, 
    0, 0, 0, 0, 5503705, 5503705, 6841958, 0, 0, 0, 0, 0, 0, 0, 6841958, 6841958, 6841958, 
    6841958, 6841958, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6841958, 5503705, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0};

static int* sword = (int*)sword_arr;

static uint32_t heart_arr[121] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16724736, 
    0, 0, 0, 16724736, 0, 0, 0, 0, 0, 16724736, 16724736, 16724736, 0, 16724736, 16724736, 
    16724736, 0, 0, 0, 16724736, 16724736, 16724736, 16724736, 16724736, 16724736, 16724736, 
    16724736, 16724736, 0, 0, 0, 16724736, 16724736, 16724736, 16724736, 16724736, 16724736, 
    16724736, 0, 0, 0, 0, 0, 16724736, 16724736, 16724736, 16724736, 16724736, 0, 0, 
    0, 0, 0, 0, 0, 16724736, 16724736, 16724736, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16724736, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static int* heart = (int*)heart_arr;

static uint32_t enemy_arr[121] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14614783, 0, 0, 0, 0, 0, 0, 0, 14614783, 
    0, 0, 14614783, 0, 0, 14614783, 0, 0, 0, 0, 0, 14614783, 14614783, 14614783, 14614783, 
    14614783, 0, 0, 0, 0, 0, 0, 14614783, 16777215, 14614783, 16777215, 14614783, 0, 
    0, 0, 0, 14614783, 14614783, 14614783, 14614783, 14614783, 14614783, 14614783, 14614783, 
    14614783, 0, 0, 0, 0, 14614783, 0, 0, 0, 14614783, 0, 0, 0, 0, 0, 0, 14614783, 14614783, 
    14614783, 14614783, 14614783, 0, 0, 0, 0, 0, 14614783, 0, 0, 14614783, 0, 0, 14614783, 
    0, 0, 0, 0, 0, 0, 0, 14614783, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static int* enemy = (int*)enemy_arr;

// Function Declarations

void draw_player(int u, int v, int key)
{
    uLCD.BLIT(u, v, 11, 11, Player);
}

void draw_portal(int u, int v)
{
    uLCD.BLIT(u, v, 11, 11, PortalSprite);
}

void draw_npc1(int u, int v)
{
    uLCD.BLIT(u, v, 11, 11, NPC1);
}

void draw_boss1(int u, int v)
{
    uLCD.BLIT(u, v, 11, 11, Boss1);
}

void draw_bluePill(int u, int v)
{
    uLCD.BLIT(u, v, 11, 11, bluePill);
}

void draw_redPill(int u, int v)
{
    uLCD.BLIT(u, v, 11, 11, redPill);
}

void draw_keySprite(int u, int v)
{
    uLCD.BLIT(u, v, 11, 11, keySprite);
}

void draw_unopenedChest(int u, int v)
{
    uLCD.BLIT(u, v, 11, 11, unopenedChest);
}

void draw_openedChest(int u, int v)
{
    uLCD.BLIT(u, v, 11, 11, openedChest);
}

void draw_speechBubble(int u, int v)
{
    uLCD.BLIT(u, v, 11, 11, speechBubble);
}

void draw_tree(int u, int v)
{
    uLCD.BLIT(u, v, 11, 11, tree);
}

void draw_sword(int u, int v)
{
    uLCD.BLIT(u, v, 11, 11, sword);
}

void draw_heart(int u, int v)
{
    uLCD.BLIT(u, v, 11, 11, heart);
}

void draw_enemy(int u, int v)
{
    uLCD.BLIT(u, v, 11, 11, enemy);
}

#define YELLOW 0xFFFF00
#define BROWN  0xD2691E
#define DIRT   BROWN
#define PURPLE 0x800080
#define LIGHTBROWN 0xC4A484
void draw_img(int u, int v, const char* img)
{
    int colors[11*11];
    for (int i = 0; i < 11*11; i++)
    {
        if (img[i] == 'R') colors[i] = RED;
        else if (img[i] == 'Y') colors[i] = YELLOW;
        else if (img[i] == 'G') colors[i] = GREEN;
        else if (img[i] == 'D') colors[i] = DIRT;
        else if (img[i] == '5') colors[i] = LGREY;
        else if (img[i] == '3') colors[i] = DGREY;
        else colors[i] = BLACK;
    }
    uLCD.BLIT(u, v, 11, 11, colors);
    wait_us(250); // Recovery time!
}

void draw_nothing(int u, int v)
{
    // Fill a tile with blackness
    uLCD.filled_rectangle(u, v, u+10, v+10, BLACK);
}

void draw_wall(int u, int v)
{
    uLCD.filled_rectangle(u, v, u+10, v+10, BROWN);
}

void draw_plant(int u, int v)
{
    uLCD.filled_rectangle(u, v, u+10, v+10, GREEN);
}

void draw_rock(int u, int v)
{
    uLCD.BLIT(u, v, 11, 11, rock);
}

void draw_upper_status(int x, int y, int health)
{   
    // Draw bottom border of status bar
    uLCD.line(0, 9, 127, 9, GREEN);
    
    // Add other status info drawing code here
    uLCD.locate(1, 0);
    uLCD.color(WHITE);
    uLCD.printf("X:%d", x);
    if (x < 10 && x >= 0) {
        uLCD.filled_rectangle(28, 0, 34, 7, BLACK);
    }
    uLCD.locate(6, 0);
    uLCD.printf("Y:%d", y);
    if (y < 10 && y >= 0) {
        uLCD.filled_rectangle(64, 0, 70, 7, BLACK);
    }
    uLCD.locate(11, 0);
    uLCD.printf("HP:%03d", health);
    
}

void draw_lower_status(bool keyObtained, bool swordObtained, int numLives)
{
    // Draw top border of status bar
    uLCD.line(0, 118, 127, 118, GREEN);
    
    
    // Add other status info drawing code here
    uLCD.locate(1, 15);
    uLCD.printf("Items:");
    if (keyObtained) {
        draw_keySprite(50, 119);
    } else {
        uLCD.filled_rectangle(50, 119, 61, 127, BLACK);
    }
    if (swordObtained) {
        draw_sword(64, 120);
    } else {
        uLCD.filled_rectangle(64, 119, 75, 127, BLACK);
    }
    draw_heart(85,119);
    uLCD.locate(14, 15);
    uLCD.printf(":%d", numLives);
}

void draw_border()
{
    uLCD.filled_rectangle(0,     9, 127,  14, WHITE); // Top
    uLCD.filled_rectangle(0,    13,   3, 114, WHITE); // Left
    uLCD.filled_rectangle(0,   114, 127, 117, WHITE); // Bottom
    uLCD.filled_rectangle(124,  14, 127, 117, WHITE); // Right
}



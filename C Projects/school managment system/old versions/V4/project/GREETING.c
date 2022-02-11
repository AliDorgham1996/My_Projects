#include <stdio.h>

static void Welcome(void);
static void Welcome_School(void);
static void Welcome_Class(void);
static void Good_bye(void);

void (*greeting_arr[])(void) = {Welcome , Welcome_School , Welcome_Class , Good_bye};  // global variable poiter

void Greeting (void(*fun)(void))
{
    fun();
}

static void Welcome(void)
{
    printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
    printf("\n\n\t\t\t\t\t     *                    *");
    printf("\n\n\t\t\t\t\t     *       Welcome      *");
    printf("\n\n\t\t\t\t\t     *                    *");
    printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
    printf("\n");
}

static void Welcome_School(void)
{
    printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
    printf("\n\n\t\t\t\t\t     *                    *");
    printf("\n\n\t\t\t\t\t     *        School      *");
    printf("\n\n\t\t\t\t\t     *                    *");
    printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
    printf("\n");
}

static void Welcome_Class(void)
{
    printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
    printf("\n\n\t\t\t\t\t     *                    *");
    printf("\n\n\t\t\t\t\t     *        Class       *");
    printf("\n\n\t\t\t\t\t     *                    *");
    printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
    printf("\n");
}

static void Good_bye(void)
{
    printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
    printf("\n\n\t\t\t\t\t     *                    *");
    printf("\n\n\t\t\t\t\t     *       Good Bye     *");
    printf("\n\n\t\t\t\t\t     *                    *");
    printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
    printf("\n");
}

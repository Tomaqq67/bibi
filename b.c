#include <stdio.h>

// typedef struct {
//     const char *name;
//     const char *species;
//     int age;
// } turtle;

// void happy_birthday(turtle *t)
// {
//     (*t).age = (*t).age + 1;
//     printf("С днем рождения, %s! Теперь тебе %i лет!\n",
//      (*t).name,  (*t).age);
// }

// int main()
// {
//     turtle myrtle = {"Тортилла", "Кожистая черепаха", 99};
//     happy_birthday(&myrtle);
//     printf("%s прожила %i лет\n", myrtle.name, myrtle.age);
//     return 0;
// }


// typedef struct {
//     const char *description;
//     float value
// } swag;

// typedef struct {
//     swag *swag;
//     const char *sequence;
// } combination;

// typedef struct{
//     combination numbers;
//     const char *make;
// } safe;

// int main()
// {
//     swag gold = {"zoloto!", 1000000.0};
//     combination numbers = {&gold, "6502"};
//     safe s = {numbers, "ramacon250"};
//     printf("Soderjimoe = %s\n", s.numbers.swag->description);
// }

// typedef union {
//     float lemon;
//     int lime_pieces;
// } lemon_lime;

// typedef struct {
//     float tequila;
//     float cointreau;
//     lemon_lime citrus;
// } margarita;

// int main()
// {
//     margarita m = {2.0, 1.0, {1}};
//     printf("%2.1f porcii tekili\n%2.1f porcii kauntro\n%2.1f porcii soka\n", m.tequila, m.citrus.lemon);
// }

#include <stdio.h>
typedef enum {
    COUNT, 
    POUNDS, 
    PINTS
} unit_of_measure;

typedef union {
    short count;
    float weight;
    float volume;
} quantity;

typedef struct {
    const char *name;
    const char *country;
    quantity amount;
    unit_of_measure units;
} fruit_order;

void display(fruit_order order)
{
    printf("Этот заказ содержит ");

    if (order.units == PINTS) {
        printf("%2.2f пинт %s\n", order.amount.volume, order.name);
    } 
    else if (order.units == POUNDS) {
        printf("%2.2f фунтов %s\n", order.amount.weight, order.name);
    } 
    else {
        printf("%i %s\n", order.amount.count, order.name);
    }
}

int main()
{
    fruit_order apples = {
        .name = "яблок", 
        .country = "Англия", 
        .amount.count = 144, 
        .units = COUNT
    };
    fruit_order strawberries = {
        .name = "клубники", 
        .country = "Испания", 
        .amount.weight = 17.6, 
        .units = POUNDS
    };
    fruit_order oj = {
        .name = "апельсинового сока", 
        .country = "США", 
        .amount.volume = 10.5, 
        .units = PINTS
    };
    display(apples);
    display(strawberries);
    display(oj);

    return 0;
}


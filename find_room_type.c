#include <stdio.h>
#include <stdlib.h>


/* define the given room types integers */

#define HALLWAY  1
#define BEDROOM  2
#define LIVING   3
#define BATHROOM 4
#define KITCHEN  5
#define LAUNDRY  6
#define STORAGE  7
#define GARAGE   8
#define BALCONY  9

void find_room_type(int room_type);

int main(int argc, char argv[]) {
  int room_type;
  while (scanf("%d",&room_type)==1){
  find_room_type(room_type);
  }
  return 0;
}

void
    find_room_type(int room_type) {
  if (room_type == HALLWAY) {
    printf("Hallway\n");
    } else if (room_type == BEDROOM) {
    printf("Bedroom\n");
    } else if (room_type == LIVING) {
    printf("Living\n");
    } else if (room_type == BATHROOM) {
    printf("Bathroom\n");
    } else if (room_type == KITCHEN) {
    printf( "Kitchen\n");
    } else if (room_type == LAUNDRY) {
    printf( "Laundry\n");
    } else if (room_type == STORAGE) {
    printf( "Storage\n");
    } else if (room_type == GARAGE) {
    printf( "Garage\n");
    } else {
    printf( "Balcony\n");
    }

  }

/* double calc_room_area(double ysize, double xsize); */
/* void print_room_table(/\*int room_type, int room_num,*\/ double xsize, double ysize); */


/* int */
/* main (int argc, int argv[]){ */
/*   double xsize, ysize; */
/*   int appartment_number; */

/*   while (scanf("%d", &appartment_number)==1) { */
/*     printf("Appartment %d\n", appartment_number); */
/*     printf("--------------\n"); */
/*     while (scanf("%lf", &xsize)==1) { */
/*       if (xsize != -1) { */
/*         scanf("%lf", &ysize); */
/*         print_room_table(xsize, ysize); */
/*       } else { */
/*         break; */
/*       } */
/*     } */
/*   } */

/* } */

/* /\* calculate the room area *\/ */
/* double */
/* calc_room_area(double ysize, double xsize){ */
/*   return (ysize*xsize); */
/* } */

/* void */
/* print_room_table(/\*int room_type,int room_num,*\/ double xsize, double ysize) { */

/*   printf("%1.2lf  %1.2lf  %1.2lf\n", xsize, ysize, calc_room_area(xsize, ysize)); */

/* } */

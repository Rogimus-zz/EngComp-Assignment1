/* coding is fun */
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


#define ROOM_STR_LEN 13



typedef struct {
  int room_type;
  int room_occurence;
  double xsize;
  double ysize;
  double area;
} room_t;





void print_room_type(int room_type);



int main(int argc, char *argv[]) {
  int appartment_number;


  room_t room;

  scanf("%d", &appartment_number);

  while(scanf("%d",&room.room_type) == 1) {
    if (room.room_type == -1) {
      break;
    } else {

      scanf("%d %lf %lf",
            &room.room_occurence,
            &room.xsize,
            &room.ysize);

      room.area = room.xsize * room.ysize;
    }

    print_room_type(room.room_type);
    printf("%d  %.2lf  %.2lf  %.2lf\n",
           room.room_occurence,
           room.xsize,
           room.ysize,
           room.area);
  }

  return 0;
}




void
print_room_type(int room_type ) {

  if (room_type == HALLWAY) {
    printf("    Hallway  ");

  } else if (room_type == BEDROOM) {
    printf("    Bedroom  ");
  } else if (room_type == LIVING) {
    printf("    Living   ");
  } else if (room_type == BATHROOM) {
    printf("    Bathroom ");
  } else if (room_type == KITCHEN) {
    printf("    Kitchen  ");
  } else if (room_type == LAUNDRY) {
    printf("    Laundry  ");
  } else if (room_type == STORAGE) {
    printf("    Storage  ");
  } else if (room_type == GARAGE) {
    printf("    Garage   ");
  } else {
    printf("    Balcony  ");
  }
}

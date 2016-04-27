/* Final solution for COMP20005 Assignment 1, April 2016.
   Roger Murray
   student number: 761654
 */
/* programming is fun */
#include <stdio.h>
#include <stdlib.h>


/* define the given room type integers */
#define HALLWAY  1
#define BEDROOM  2
#define LIVING   3
#define BATHROOM 4
#define KITCHEN  5
#define LAUNDRY  6
#define STORAGE  7
#define GARAGE   8
#define BALCONY  9

#define MAXROOMS 100               /* maximum number of rooms per apartment */
#define MAXAPARTMENTS 100          /* maximum number of apartments */

                                   /* formatting for Stage 4 table */
#define DIVIDER "+-------+----------------+----------------+----------------+"
#define HEADER  "| Apart |    Dry areas   |    Wet areas   |  Utility areas |"

/* type definitions of structs */
typedef struct {
  int room_type;
  int room_occurence;
  double xsize;
  double ysize;
  double area;
} room_t;

typedef struct {
  int apartment_number;
  room_t room[MAXROOMS+1]; /* including the "-1" */
  double total_area;
} apartment_t;

typedef struct {
  double dry_area;
  double dry_area_percent;
  double wet_area;
  double wet_area_percent;
  double storage_area;
  double storage_area_percent;
} areas_t;

/* function prototypes */
void Print_Stage_3(apartment_t apartments[], int num_apartments);
void Print_Stage_4(apartment_t apartments[], int num_apartments);
void Print_Room_Type(int room_type);
areas_t Find_Room_Area(apartment_t x);

/*The main function scans in the relevant data, and then calls on the
  appropriate functions to produce the correct output.
 */
int main(int argc, char *argv[]) {
  int room_index;
  int apartment_index;
  apartment_t apartments[MAXAPARTMENTS]; /* storage for all of the input data */
  apartment_index = 0;

  /* Main loop: read in the data for every apartment, room by room.
   */
  while(scanf("%d", &apartments[apartment_index].apartment_number) == 1) {
    room_index = 0;
    while(scanf("%d", &apartments[apartment_index].room[room_index].room_type)
          == 1) {
      /* the "-1" which signifies no more rooms will always be assigned
         to room_type, so check this before proceeding */
      if(apartments[apartment_index].room[room_index].room_type == -1 ) {
        apartment_index++;
        break;
      } else {
        scanf("%d %lf %lf",
              &apartments[apartment_index].room[room_index].room_occurence,
              &apartments[apartment_index].room[room_index].xsize,
              &apartments[apartment_index].room[room_index].ysize);
        /* calculate area */
        apartments[apartment_index].room[room_index].area =
          apartments[apartment_index].room[room_index].xsize
          * apartments[apartment_index].room[room_index].ysize;

        apartments[apartment_index].total_area +=
          apartments[apartment_index].room[room_index].area;
      }
      room_index++;
    }
  }

  /* output for Stage 3 */
  Print_Stage_3(apartments, apartment_index);  /* appartment_index is
                                                  equivalent to the number
                                                  of appartments */

  /* output for Stage 4 */
  Print_Stage_4(apartments, apartment_index);

  /* finished! */
  return 0;
}


/* generate the output for stage 3
 */
void
Print_Stage_3(apartment_t aps[], int num_apartments) {
  int i;
  int room_index;
  double area_sum; /* the total area of the current room occurence */

  /* loop through each room in each apartment in aps and print output */
  for(i=0; i<num_apartments; i++) {
    printf("Apartment %3d\n", aps[i].apartment_number);
    printf("-------------\n");
    room_index = 0;
    area_sum = aps[i].room[room_index].area;

    while(aps[i].room[room_index].room_type != -1){
      Print_Room_Type(aps[i].room[room_index].room_type);

      if((room_index < MAXROOMS && aps[i].room[room_index].room_type ==
          aps[i].room[room_index+1].room_type) &&
         (aps[i].room[room_index].room_occurence ==
          aps[i].room[room_index+1].room_occurence)) {
                  /* check if the next room is the same as the current room */
        printf("%2d", aps[i].room[room_index].room_occurence);
        printf(" %5.2f",  aps[i].room[room_index].xsize);
        printf(" %5.2f",  aps[i].room[room_index].ysize);
        printf("   ---");

        area_sum += aps[i].room[room_index+1].area;
      } else {
        printf("%2d", aps[i].room[room_index].room_occurence);
        printf(" %5.2f",  aps[i].room[room_index].xsize);
        printf(" %5.2f",  aps[i].room[room_index].ysize);
        printf(" %6.2f",  area_sum);

        if (room_index < MAXROOMS){
          area_sum = aps[i].room[room_index+1].area;
        }
      }
      printf("\n");
      room_index++;
    }
    printf("    Total area             %6.2lf metres^2\n\n",
           aps[i].total_area);
  }
}

/* generate the output for stage 4 (the table)
 */
void
Print_Stage_4(apartment_t ap[], int num_apartments) {
  areas_t ap_area;
  int i;

  printf("%s\n", DIVIDER);
  printf("%s\n", HEADER);
  printf("%s\n", DIVIDER);
  for(i=0; i < num_apartments; i++) {
    ap_area = Find_Room_Area(ap[i]);
    printf("|");
    printf("  %3d  | ", ap[i].apartment_number);
    printf("%6.2lf %5.1lf%%  | ", ap_area.dry_area, ap_area.dry_area_percent);
    printf("%6.2lf %5.1lf%%  | ", ap_area.wet_area, ap_area.wet_area_percent);
    printf("%6.2lf %5.1lf%%  ", ap_area.storage_area,
           ap_area.storage_area_percent);
    printf("|  \n");
  }
  printf("%s\n", DIVIDER);
  return;
}

/* prints the room type depending on the given integer
 */
void
Print_Room_Type(int room_type ) {
  if(room_type == HALLWAY) {
    printf("    Hallway ");
  } else if(room_type == BEDROOM) {
    printf("    Bedroom ");
  } else if(room_type == LIVING) {
    printf("    Living  ");
  } else if(room_type == BATHROOM) {
    printf("    Bathroom");
  } else if(room_type == KITCHEN) {
    printf("    Kitchen ");
  } else if(room_type == LAUNDRY) {
    printf("    Laundry ");
  } else if(room_type == STORAGE) {
    printf("    Storage ");
  } else if(room_type == GARAGE) {
    printf("    Garage  ");
  } else if(room_type == BALCONY) {
    printf("    Balcony ");
  } else {
    exit(EXIT_FAILURE);
  }
  return;
}

/* takes a single apartment of type "apartment_t" and returns a struct of
   type "areas_t" after calculating the relevant areas
 */
areas_t
Find_Room_Area(apartment_t ap) {
  areas_t areas;
  int i;

  areas.dry_area =
    areas.dry_area_percent =
    areas.wet_area =
    areas.wet_area_percent =
    areas.storage_area =
    areas.storage_area_percent
    = 0;

  i = 0;
  while(ap.room[i].room_type != -1) {
    if(ap.room[i].room_type == HALLWAY ||
       ap.room[i].room_type == BEDROOM ||
       ap.room[i].room_type == LIVING) {
      areas.dry_area += ap.room[i].area;
    } else if(ap.room[i].room_type == BATHROOM ||
              ap.room[i].room_type == KITCHEN ||
              ap.room[i].room_type == LAUNDRY) {
      areas.wet_area += ap.room[i].area;
    } else if(ap.room[i].room_type == STORAGE ||
              ap.room[i].room_type == GARAGE ||
              ap.room[i].room_type == BALCONY) {
      areas.storage_area += ap.room[i].area;
    } else {
      exit(EXIT_FAILURE);
    }
    i++;
  }

  areas.dry_area_percent = 100 * areas.dry_area / ap.total_area;
  areas.wet_area_percent = 100 * areas.wet_area / ap.total_area;
  areas.storage_area_percent = 100 * areas.storage_area / ap.total_area;

  return areas;
}


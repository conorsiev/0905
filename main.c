#include <stdio.h>
#include <string.h>
#include "twitter_create.h"

int main() {
    twitter twit1;
    create_twitter_system(&twit1);
    printf("\nCurrent user is: %s", twit1.users[twit1.counter].username);
    follow(&twit1);
    unfollow(&twit1);


    return 0;
}

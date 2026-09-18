#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char username[21];
    char password[21];

    struct User *followers[100];
    int followerCount;

    struct User *following[100];
    int followingCount;

    struct User *next;
};

/* Find user */
struct User* findUser(struct User *head, char username[]) {
    struct User *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->username, username) == 0)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

/* Register */
struct User* registerUser(struct User *head) {
    char username[21], password[21];

    scanf("%20s", username);
    scanf("%20s", password);

    if (findUser(head, username) != NULL)
        return NULL;

    struct User *newUser =
        (struct User *)malloc(sizeof(struct User));

    if (newUser == NULL)
        return head;

    strcpy(newUser->username, username);
    strcpy(newUser->password, password);

    newUser->followerCount = 0;
    newUser->followingCount = 0;

    newUser->next = head;

    return newUser;
}

/* Login */
struct User* loginUser(struct User *head) {
    char username[21], password[21];

    scanf("%20s", username);
    scanf("%20s", password);

    struct User *user = findUser(head, username);

    if (user != NULL && strcmp(user->password, password) == 0)
        return user;

    return NULL;
}

/* Follow */
int followUser(struct User *currentUser, struct User *otherUser) {

    if (currentUser == NULL || otherUser == NULL)
        return 0;

    if (currentUser == otherUser)
        return 0;

    /* Already following? */
    for (int i = 0; i < currentUser->followingCount; i++) {
        if (currentUser->following[i] == otherUser)
            return 0;
    }

    /* Lists full? */
    if (currentUser->followingCount >= 100 ||
        otherUser->followerCount >= 100)
        return 0;

    currentUser->following[currentUser->followingCount]
        = otherUser;

    currentUser->followingCount++;

    otherUser->followers[otherUser->followerCount]
        = currentUser;

    otherUser->followerCount++;

    return 1;
}

/* Unfollow */
int unfollowUser(struct User *currentUser, struct User *otherUser) {

    if (currentUser == NULL || otherUser == NULL)
        return 0;

    int index = -1;

    /* Find otherUser in following list */
    for (int i = 0; i < currentUser->followingCount; i++) {
        if (currentUser->following[i] == otherUser) {
            index = i;
            break;
        }
    }

    if (index == -1)
        return 0;

    /* Remove from following */
    for (int i = index;
         i < currentUser->followingCount - 1;
         i++) {

        currentUser->following[i] =
            currentUser->following[i + 1];
    }

    currentUser->followingCount--;

    /* Find currentUser in otherUser's followers */
    index = -1;

    for (int i = 0; i < otherUser->followerCount; i++) {
        if (otherUser->followers[i] == currentUser) {
            index = i;
            break;
        }
    }

    if (index != -1) {

        for (int i = index;
             i < otherUser->followerCount - 1;
             i++) {

            otherUser->followers[i] =
                otherUser->followers[i + 1];
        }

        otherUser->followerCount--;
    }

    return 1;
}

/* Remove follower */
int removeFollower(struct User *currentUser,
                   struct User *otherUser) {

    if (currentUser == NULL || otherUser == NULL)
        return 0;

    int index = -1;

    /* Find otherUser in followers */
    for (int i = 0; i < currentUser->followerCount; i++) {

        if (currentUser->followers[i] == otherUser) {
            index = i;
            break;
        }
    }

    if (index == -1)
        return 0;

    /* Remove follower */
    for (int i = index;
         i < currentUser->followerCount - 1;
         i++) {

        currentUser->followers[i] =
            currentUser->followers[i + 1];
    }

    currentUser->followerCount--;

    /* Remove currentUser from other's following */
    index = -1;

    for (int i = 0; i < otherUser->followingCount; i++) {

        if (otherUser->following[i] == currentUser) {
            index = i;
            break;
        }
    }

    if (index != -1) {

        for (int i = index;
             i < otherUser->followingCount - 1;
             i++) {

            otherUser->following[i] =
                otherUser->following[i + 1];
        }

        otherUser->followingCount--;
    }

    return 1;
}

/* MAIN FUNCTION */
int main() {

    struct User *head = NULL;
    struct User *currentUser = NULL;

    int choice;
    char username[21];

    while (1) {

        if (currentUser == NULL) {

            printf("\n1. Register\n");
            printf("2. Login\n");
            printf("3. Exit\n");

            scanf("%d", &choice);

            if (choice == 1) {

                struct User *oldHead = head;

                head = registerUser(head);

                if (head != oldHead)
                    printf("Registration successful %s.\n",
                           head->username);
                else
                    printf("Registration failed.\n");
            }

            else if (choice == 2) {

                currentUser = loginUser(head);

                if (currentUser != NULL)
                    printf("Login successful %s.\n",
                           currentUser->username);
                else
                    printf("Login failed.\n");
            }

            else if (choice == 3) {
                break;
            }
        }

        else {

            printf("\n1. Follow User\n");
            printf("2. View Followers\n");
            printf("3. View Following\n");
            printf("4. Unfollow User\n");
            printf("5. Remove Follower\n");
            printf("6. Logout\n");

            scanf("%d", &choice);

            if (choice == 1) {

                scanf("%20s", username);

                struct User *otherUser =
                    findUser(head, username);

                if (followUser(currentUser, otherUser))
                    printf("Successfully followed %s.\n",
                           username);
                else
                    printf("Cannot follow %s.\n", username);
            }

            else if (choice == 2) {

                printf("\nFollowers:\n");

                if (currentUser->followerCount == 0) {
                    printf("No followers.\n");
                }
                else {
                    for (int i = 0;
                         i < currentUser->followerCount;
                         i++) {

                        printf("%s\n",
                               currentUser->followers[i]->username);
                    }
                }
            }

            else if (choice == 3) {

                printf("\nFollowing:\n");

                if (currentUser->followingCount == 0) {
                    printf("No following users.\n");
                }
                else {
                    for (int i = 0;
                         i < currentUser->followingCount;
                         i++) {

                        printf("%s\n",
                               currentUser->following[i]->username);
                    }
                }
            }

            else if (choice == 4) {

                scanf("%20s", username);

                struct User *otherUser =
                    findUser(head, username);

                if (unfollowUser(currentUser, otherUser))
                    printf("Successfully unfollowed %s.\n",
                           username);
                else
                    printf("Cannot unfollow %s.\n", username);
            }

            else if (choice == 5) {

                scanf("%20s", username);

                struct User *otherUser =
                    findUser(head, username);

                if (removeFollower(currentUser, otherUser))
                    printf("%s was removed from your followers.\n",
                           username);
                else
                    printf("%s is not your follower.\n", username);
            }

            else if (choice == 6) {

                printf("Logged out.\n");
                currentUser = NULL;
            }
        }
    }

    return 0;
}
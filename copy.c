        
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
                    printf("%s was removed from your followers.\n", username);
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
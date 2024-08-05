#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define MAX_STRING_LENGTH 100

struct TextData {
    char **lines;
    int numLines;
};

void readTextFile(const char *filename, struct TextData *data) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_STRING_LENGTH];
    data->numLines = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        data->numLines++;
    }

    rewind(file);

    data->lines = (char **)malloc(data->numLines * sizeof(char *));
    if (data->lines == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < data->numLines; ++i) {
        data->lines[i] = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        if (data->lines[i] == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }

        fgets(data->lines[i], MAX_STRING_LENGTH, file);
    }

    fclose(file);
}

void freeTextData(struct TextData *data) {
    for (int i = 0; i < data->numLines; ++i) {
        free(data->lines[i]);
    }
    free(data->lines);
}

typedef struct WiFi_Profile{
    char device_name[50];
    int priority_level;
    char network_details[100];
    int allocated_bandwidth;
} WiFi_Profile;

int comparePriority(const void *a, const void *b) {
    WiFi_Profile *profileA = (WiFi_Profile *)a;
    WiFi_Profile *profileB = (WiFi_Profile *)b;

    return profileB->priority_level - profileA->priority_level;
}


void allocateBandwidth(WiFi_Profile *wifi_profiles, int num_profiles, int total_bandwidth) {
    for (int i = 0; i < num_profiles - 1; i++) {
        for (int j = 0; j < num_profiles - i - 1; j++) {
            if (wifi_profiles[j].priority_level > wifi_profiles[j + 1].priority_level) {
                WiFi_Profile temp = wifi_profiles[j];
                wifi_profiles[j] = wifi_profiles[j + 1];
                wifi_profiles[j + 1] = temp;
            }
        }
    }

    int current_bandwidth = total_bandwidth;
    for (int i = 0; i < num_profiles; i++) {
        int bandwidth_per_device = ((num_profiles - wifi_profiles[i].priority_level + 1) * total_bandwidth)/((num_profiles*(num_profiles + 1)) / 2);
        wifi_profiles[i].allocated_bandwidth = bandwidth_per_device;
        current_bandwidth -= bandwidth_per_device;
    }
}

void add_device(WiFi_Profile *wifi_profiles, int *num_profiles, WiFi_Profile new_profile) {
    wifi_profiles[*num_profiles] = new_profile;
    (*num_profiles)++;
}

void remove_device(WiFi_Profile *wifi_profiles, int *num_profiles, char *device_name) {
    int index_to_remove = -1;

    for (int i = 0; i < *num_profiles; i++) {

        if (strcmp(wifi_profiles[i].device_name, device_name) == 0) {
            index_to_remove = i;
            break;
        }
    }

    if (index_to_remove != -1) {
        for (int i = index_to_remove; i < (*num_profiles) - 1; i++) {
            wifi_profiles[i] = wifi_profiles[i + 1];
        }
        for(int i=index_to_remove;i<(*num_profiles);i++)
        {
            wifi_profiles[i].priority_level=wifi_profiles[i].priority_level-1;
        }
        (*num_profiles)--;
    }

}

void edit_device(WiFi_Profile *wifi_profiles, int num_profiles, char *device_name, int new_priority) {
    for (int i = 0; i < num_profiles; i++) {

        if (strcmp(wifi_profiles[i].device_name, device_name) == 0) {

            wifi_profiles[i].priority_level = new_priority;

            for(int k = i+1 ; k< num_profiles ; k++)
            {
                wifi_profiles[k].priority_level -=1;
            }

            for (int k = 0; k < num_profiles; k++) {
                for (int j = k+1; j < num_profiles; j++) {
                    if (wifi_profiles[k].priority_level > wifi_profiles[j].priority_level) {
                        WiFi_Profile temp;
                        temp = wifi_profiles[k];
                        wifi_profiles[k] = wifi_profiles[j];
                        wifi_profiles[j] = temp;
                    }
                }
            }

            for (int k = 0; k < num_profiles; k++) {
                for (int j = k+1; j < num_profiles; j++) {
                    if (wifi_profiles[k].priority_level == wifi_profiles[j].priority_level) {
                        WiFi_Profile temp;
                        temp = wifi_profiles[k];
                        wifi_profiles[k] = wifi_profiles[j];
                        wifi_profiles[j] = temp;
                        break;
                    }
                }
            }

            int z=-1;
            for(int k = 0 ; k<num_profiles ; k++)
            {
                if(wifi_profiles[k].priority_level== new_priority)
                {
                    z=k;
                    break;
                }
            }

            for(int k= z+1 ; k < num_profiles ; k++)
            {
                wifi_profiles[k].priority_level+=1;
            }

            break;
        }
    }

}

void displayDevice(const WiFi_Profile *profiles, int num_profiles) {
    printf("Device List:\n");
    printf("Device name \t Device Priority \t Ip Address\n");
    for (int i = 0; i < num_profiles; ++i) {
        printf("%s\t%d\t\t%s", profiles[i].device_name, profiles[i].priority_level, profiles[i].network_details);
    }
}

char* removeNewline(const char* original) {
    size_t length = strlen(original);

    if (length > 0 && original[length - 1] == '\n') {
        char* result = (char*)malloc(length);
        strncpy(result, original, length - 1);
        result[length - 1] = '\0';

        return result;
    } else {
        return strdup(original);
    }
}

void displayDeviceWithBandwidth(const WiFi_Profile *profiles, int num_profiles) {
    printf("Device List with Bandwidth:\n");

    printf("\n+-----------------------------------------------------------------------------+\n");
    printf("|                                                                             |\n");
    printf("|Device name \t Device Priority \t Allocated Bandwidth \t Ip Address   |\n");
    for (int i = 0; i < num_profiles; ++i) {

        strcpy(profiles[i].network_details, removeNewline(profiles[i].network_details));
        printf("|%s\t%d\t\t\t%d mb\t\t%s |\n", profiles[i].device_name, profiles[i].priority_level, profiles[i].allocated_bandwidth, profiles[i].network_details );
    }
    printf("|                                                                             |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

void freeProfiles(WiFi_Profile *profiles, int num_profiles) {
    free(profiles);
}

int main() {

    struct TextData textData;
    const char *filename = "dataset.txt";

    readTextFile(filename, &textData);

    int num_profiles = 0;
    int I = 11,c=0;
    WiFi_Profile profile[100];

    for(int i=0;i<10;i++)
    {

        char *device = textData.lines[i];
        char *token = strtok(device,";");

        WiFi_Profile new_profile;

        for(int j=0;j<sizeof(token);j++)
        {
            if(token[j]=='_')
            {
                token[j]=' ';
            }
        }

        strcpy(new_profile.device_name, token);
        token = strtok(NULL,";");
        new_profile.priority_level = i+1;
        strcpy(new_profile.network_details, token);

        add_device(profile, &num_profiles, new_profile);

    }
    freeTextData(&textData);


    displayDevice(profile,num_profiles);


    printf("MENU: \nPress the required option\n");
    printf("1.Add a new device\n2.Remove a device\n3.Edit priority order\n");

    while (1) {

        char a;
        printf("Would you like to continue?(y/n): ");
        scanf(" %c", &a);

        if (a == 'n' || a == 'N')
            break;

        else if (a == 'y' || a == 'Y') {

            int x;
            printf("\nEnter the preferred option: ");
            scanf("%d",&x);

            switch(x)
            {
                case 1: {
                    WiFi_Profile add_profile;
                    char device_Name[100];

                    printf("\nEnter the device name: ");

                    fflush(stdin);
                    fgets(device_Name,sizeof(device_Name),stdin);

                    if (  strlen(device_Name)>0 && device_Name[strlen(device_Name) - 1] == '\n') {
                        device_Name[strlen(device_Name) - 1] = '\0';
                    }
                    int space=21-strlen(device_Name);
                    for(int k=0;k<space;k++)
                    {
                        strcat(device_Name," ");
                    }


                    strcpy(add_profile.device_name, device_Name);
                    add_profile.priority_level = I;

                    int a=I*5;
                    char b[4];
                    char Ip[]=" 192.168.1.";
                    snprintf(b,sizeof(b),"%d",a);
                    strcat(Ip,b);
                    strcat(Ip,"\n");
                    strcpy(add_profile.network_details, Ip);
                    add_device(profile, &num_profiles, add_profile);
                    I=I+1;

                    char f;
                    printf("\nWould you like to see the updated list(y/n): ");
                    scanf(" %c", &f);
                    if (f == 'n' || f == 'N')
                    {
                        break;
                    }
                    else if (f == 'y' || f == 'Y')
                    {
                        displayDevice(profile,num_profiles);
                    }

                    break;
                }
                case 2: {
                    char device_Name[100];
                    printf("Enter the name of the device: ");
                    fflush(stdin);
                    fgets(device_Name, sizeof(device_Name), stdin);

                    if (  strlen(device_Name)>0 && device_Name[strlen(device_Name) - 1] == '\n') {
                        device_Name[strlen(device_Name) - 1] = '\0';
                    }
                    int space=21-strlen(device_Name);
                    for(int k=0;k<space;k++)
                    {
                        strcat(device_Name," ");
                    }

                    remove_device(profile, &num_profiles, device_Name);

                    char b;
                    printf("\nWould you like to see the updated list(y/n): ");
                    scanf(" %c", &b);
                    if (b == 'n' || b == 'N')
                    {
                        break;
                    }
                    else if (b == 'y' || b == 'Y')
                    {
                        displayDevice(profile,num_profiles);
                    }

                    break;
                }
                case 3:
                {
                    char device_Name[100];
                    int new_priority;
                    printf("Enter the name and the new priority of the device: ");
                    fflush(stdin);
                    fgets(device_Name,sizeof(device_Name),stdin);

                    if (  strlen(device_Name)>0 && device_Name[strlen(device_Name) - 1] == '\n') {
                        device_Name[strlen(device_Name) - 1] = '\0';
                    }
                    int space=21-strlen(device_Name);
                    for(int k=0;k<space;k++)
                    {
                        strcat(device_Name," ");
                    }

                    scanf("%d",&new_priority);
                    edit_device(profile,num_profiles,device_Name,new_priority);

                    char b;
                    printf("\nWould you like to see the updated list(y/n): ");
                    scanf(" %c", &b);
                    if (b == 'n' || b == 'N')
                    {
                        break;
                    }
                    else if (b == 'y' || b == 'Y')
                    {
                        displayDevice(profile,num_profiles);
                    }

                    break;
                }
                default:
                    printf("Please enter a valid option\n");
                    break;
            }
            continue;
        } else {
            continue;
        }
    }

    int total_bandwidth=1000;

    allocateBandwidth(profile, num_profiles, total_bandwidth);

    printf("Allocating Bandwidth. Please Stand By.");
    for (int i = 0; i < 10; ++i) {
        printf(".");
        fflush(stdout);
        Sleep(250);
    }

    printf("\n --------------------------------------------------------------------------\n");
    printf("|                                                                          |\n");
    printf("|The System Router allocates a total of %d mbs to every device per cycle.|\n",total_bandwidth);
    printf("|                                                                          |\n");
    printf(" --------------------------------------------------------------------------\n");

    displayDeviceWithBandwidth(profile,num_profiles);
    printf("\nThank you");
    freeProfiles(profile, num_profiles);
    return 0;
}

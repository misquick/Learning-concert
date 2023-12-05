#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
} WordInfo;

WordInfo chooseRandomWord(WordInfo* words, int count) {
    int randomIndex = rand() % count;
    return words[randomIndex];
}

int guessLetter(char* word, char letter, char* guessedWord) {
    int correctGuess = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == letter) {
            guessedWord[i] = letter;
            correctGuess = 1;
        }
    }
    return correctGuess;
}

int main() {
    WordInfo words[MAX_WORDS] = {
        {"apple", "A fruit that is typically red or green."},
        {"banana", "A long curved fruit that grows in clusters."},
        {"orange", "A round fruit with a tough bright reddish-yellow rind."},
        {"computer", "An electronic device for storing and processing data."},
        {"guitar", "A musical instrument with six strings."},
        {"mountain", "A large natural elevation of the earth's surface."},
        {"ocean", "A vast expanse of saltwater."},
        {"jungle", "A land covered with dense vegetation and often found in tropical areas."},
        {"robot", "A machine capable of carrying out tasks automatically."},
        {"universe", "All of space, time, matter, and energy."},
        {"sunflower", "A tall North American plant of the daisy family, with very large golden-rayed flowers."},
        {"elephant", "A heavy plant-eating mammal with a prehensile trunk, long curved ivory tusks, and large ears."},
        {"symphony", "An elaborate musical composition for full orchestra, typically in four movements."},
        {"ballet", "A classical dance form demanding grace and precision and employing formalized steps and gestures."},
        {"dinosaur", "A fossil reptile of the Mesozoic era, often reaching an enormous size."},
        {"astronomy", "The branch of science that deals with celestial objects, space, and the physical universe as a whole."},
        {"quasar", "A massive and extremely remote celestial object, emitting exceptionally large amounts of energy."},
        {"volcano", "A mountain or hill, typically conical, having a crater or vent through which lava, rock fragments, hot vapor, and gas are or have been erupted."},
        {"lighthouse", "A tower or other structure containing a beacon light to warn or guide ships at sea."},
        {"waterfall", "A cascade of water falling from a height, formed when a river or stream flows over a precipice or steep incline."},
        {"architecture", "The art or practice of designing and constructing buildings."},
        {"hurricane", "A storm with a violent wind, in particular a tropical cyclone in the Caribbean."},
        {"telescope", "An optical instrument designed to make distant objects appear nearer, containing an arrangement of lenses, or of curved mirrors and lenses."},
        {"constellation", "A group of stars forming a recognizable pattern that is traditionally named after its apparent form or identified with a mythological figure."},
        {"rainforest", "A luxuriant, dense forest rich in biodiversity, typically found in tropical areas with consistently heavy rainfall."},
        {"phoenix", "A mythical bird that is said to be cyclically regenerated or reborn from the ashes of its predecessor."},
        {"avalanche", "A sudden and overwhelming quantity of things, typically words or feelings."},
        {"monastery", "A building or buildings occupied by a community of monks living under religious vows."},
        {"paradox", "A seemingly absurd or self-contradictory statement or proposition that when investigated or explained may prove to be well founded or true."},
        {"cathedral", "The principal church of a diocese, with which the bishop is officially associated."},
        {"algorithm", "A process or set of rules to be followed in calculations or other problem-solving operations, especially by a computer."},
        {"cactus", "A succulent plant with a thick, fleshy stem that typically bears spines, lacks leaves, and has brilliantly colored flowers."},
        {"diamond", "A precious stone consisting of a clear and typically colorless crystalline form of pure carbon."},
        {"pyramid", "A structure with a square or triangular base and four triangular sides, built as a tomb over a Pharaoh in ancient Egypt."},
        {"watermelon", "A large, roundish fruit with a green rind and juicy, sweet, red, or pinkish flesh."},
        {"butterfly", "An insect with two pairs of large wings covered in microscopic scales, typically brightly colored and held erect when at rest."},
        {"library", "A building or room containing collections of books, periodicals, and sometimes films and recorded music for people to read, borrow, or refer to."},
        {"giraffe", "A large African mammal with a very long neck and forelegs, having a coat patterned with brown patches separated by lighter lines."},
        {"eclipse", "An obscuring of the light from one celestial body by the passage of another between it and the observer or between it and its source of illumination."},
        {"whale", "A very large marine mammal with a streamlined hairless body, a horizontal tail fin, and a blowhole on top of the head for breathing."},
        {"symphony", "An elaborate musical composition for full orchestra, typically in four movements."},
        {"cappuccino", "An Italian coffee made with espresso and steamed milk, often topped with whipped cream or sprinkled with chocolate."},
        {"chocolate", "A sweet food made from roasted and ground cacao seeds, typically sweetened and eaten as confectionery."},
        {"telephone", "An instrument used for transmitting sound, especially speech, over a distance."},
        {"keyboard", "A panel of keys for operating a typewriter, computer, or other mechanical device."},
        {"umbrella", "A device consisting of a circular canopy of cloth on a folding metal frame supported by a central rod, used as protection against rain or sometimes sun."},
        {"bicycle", "A vehicle with two wheels held in a frame one behind the other, propelled by pedals and steered with handlebars attached to the front wheel."},
        {"astronaut", "A person who is trained to travel into outer space."},
        {"kangaroo", "A large plant-eating marsupial with a long powerful tail and strongly developed hindlimbs, that lives in Australia."},
        {"pyramid", "A structure with a square or triangular base and four triangular sides, built as a tomb over a Pharaoh in ancient Egypt."}
    };
    int wordsCount = sizeof(words) / sizeof(words[0]);

    srand(time(NULL));

    WordInfo chosenWordInfo = chooseRandomWord(words, wordsCount);
    char* chosenWord = chosenWordInfo.word;
    int wordLength = strlen(chosenWord);

    int maxAttempts;
    switch (wordLength) {
        case 3:
            maxAttempts = 6;
            break;
        case 4:
        case 5:
            maxAttempts = 8;
            break;
        case 6:
        case 7:
            maxAttempts = 10;
            break;
        case 8:
        case 9:
            maxAttempts = 12;
            break;
        case 10:
        case 11:
            maxAttempts = 14;
            break;
        default:
            maxAttempts = 16;
    }

    char guessedWord[MAX_WORD_LENGTH];
    memset(guessedWord, '_', wordLength);
    guessedWord[wordLength] = '\0';

    printf("Guess the word (amount of letters: %d): %s\n", wordLength, guessedWord);
    printf("Description: %s\n", chosenWordInfo.description);

    int attempts = 0;
    while (attempts < maxAttempts) {
        char guess;
        printf("Input a letter: ");
        scanf(" %c", &guess);

        if (guessLetter(chosenWord, guess, guessedWord)) {
            printf("Correct! Current word is: %s\n", guessedWord);
        } else {
            printf("Incorrect. Attempts left: %d\n", maxAttempts - attempts - 1);
        }

        if (strcmp(chosenWord, guessedWord) == 0) {
            printf("Congratulations! You guessed the word: %s\n", chosenWord);
            return 0;
        }

        attempts++;
    }

    char finalGuess[MAX_WORD_LENGTH];
    printf("You have one last try left. Try to guess the word: ");
    scanf("%s", finalGuess);

    if (strcmp(chosenWord, finalGuess) == 0) {
        printf("Congratulations! You guessed the word: %s\n", chosenWord);
    } else {
        printf("Unfortunately, you didn't guess the word correctly. The hidden word was: %s\n", chosenWord);
    }

    return 0;
}

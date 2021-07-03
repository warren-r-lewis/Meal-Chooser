#include <iostream>

using namespace std;


/*Function that asks how many ingredients you want and returns an int*/
int NumberOfIngredients() 
{
    int numberOfIngredients;
    cout << "Roughly how many ingredients do you want?\n 5, 10, 15, 20" << endl;
    cin >> numberOfIngredients;

    while (numberOfIngredients != 5 && numberOfIngredients != 10 && numberOfIngredients != 15 && numberOfIngredients != 20)
    {
        cout << "Invalid input, please enter: '5', '10', '15', or '20'" << endl;
        cin >> numberOfIngredients;
    }

    return numberOfIngredients;
}

/*Function that asks your desired cook time and returns an int*/
int CookTime() 
{
    int cookTime;

    cout << "What is your preffered cooktime, in minutes? \n 15, 30, 45, 60" << endl;
    cin >> cookTime;

    while (cookTime != 15 && cookTime != 30 && cookTime != 45 && cookTime != 60) 
    {
        cout << "Invalid input, please enter: '15', '30', '45', or '60'" << endl;
        cin >> cookTime;
    }
    return cookTime;
}

/*class for creating meal objects*/
class Meal 
{
public:
    
    string name;
    bool spicy;
    int numberOfIngredients;
    int cookTime;
    string Recipe;

    Meal(string aName, bool aSpicy, int aNumberOfIngredients, int aCookTime, string aRecipe) 
    {
        name = aName;
        spicy = aSpicy;
        numberOfIngredients = aNumberOfIngredients;
        cookTime = aCookTime;
        Recipe = aRecipe;
    }


    /*Tells the user how difficult the recipe is*/
    void DifficultyLevel() 
    {
        if (numberOfIngredients < 10 && cookTime <= 45)
        {
            cout << "This recipe is easy." << endl;
        }
        else 
        {
            cout << "This recipe is difficult." << endl;
        }

    }
};

/*Funciton that tells you all the infomration about the suggested meal*/
void RecipeSuggestion(Meal suggestedMeal) 
{
    cout << "\n We recomend you make: " << suggestedMeal.name << "!" << endl;
    cout << "Estimated number of ingredients: " << suggestedMeal.numberOfIngredients << endl;
    cout << "Estimated cook time: " << suggestedMeal.cookTime << endl;
    if (suggestedMeal.spicy)
    {
        cout << "This meal is spicy" << endl;
    }
    cout << "Difficulty level: " << suggestedMeal.cookTime << endl;
    cout << "Recipe URL : " << suggestedMeal.Recipe << endl;
}

/*Function that takes all of the parameters set by the users and compares them against the recipes. Returns a meal that matches the parameters*/
void RecipeCompare()
{

    int cookTime = CookTime();
    int numberOfIngredients = NumberOfIngredients();

    Meal SuasagePasta("Pasta with White Suasage Sauce", false, 5, 15, "https://cooking.nytimes.com/recipes/5443-pasta-with-white-sausage-sauce");
    Meal SpicyPorkNoodles("Spicy-Sweet Sambal Pork Noodles", true, 10, 60, "https://www.bonappetit.com/recipe/spicy-sweet-sambal-pork-noodles");
    Meal DrunkenNoodles("Jet Tila's Famous Drunken Noodles", true, 15, 10, "https://www.foodnetwork.com/fn-dish/chefs/2017/06/jet-tilas-recipe-for-famous-drunken-noodles-is-the-only-one-you-need");
    Meal BakedZiti("Babish's Baked Rigatoni", false, 15, 60, "https://www.bingingwithbabish.com/recipes/ziti-lasagna");
    Meal BoKho("Bo Kho (Vietnamese Braised Beef Stew)", true, 20, 60, "https://cooking.nytimes.com/recipes/1019891-bo-kho-vietnamese-braised-beef-stew?action=click&module=Global%20Search%20Recipe%20Card&pgType=search&rank=1");

    Meal Meals[] = { SuasagePasta, SpicyPorkNoodles, DrunkenNoodles, BakedZiti };

    for (Meal i : Meals)
    {
        if ((i.cookTime <= cookTime && i.numberOfIngredients <= numberOfIngredients))
        {

            Meal chosenMeal = i;
            RecipeSuggestion(i);

        }
    }
}

/*Function to call all the other functions*/
void Greeting()
{
    cout << "Allow me to assist you in choosing a meal!\n" << endl;
    cout << "*Please note, cook time and ingredients are rounded to the nearest value.\n" << endl;
    cout << "*We will recomend any recipes that are less than, or equal too, you given cook time and ingredients \n" << endl;
    RecipeCompare();
}

int main()
{
    Greeting();
}



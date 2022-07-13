#include "gtest/gtest.h"
#include "MainMenu.cpp"

/*MainMenu*/
TEST(outputOldUserCSV, EmptyCSV) {
	string userName = "unittest1";
	MainMenu menu;
	menu.outputOldUserFile(userName);
	EXPECT_EQ(menu.getDateSize(), 0);
}

/*DeleteTask*/
TEST(deleteTask, SuccesfulDeletion) {
	string title = "Doggy";
	MainMenu test;

	Task* A = new Task("Doggy", "It's an animal", 3, "Dog");
	 
	test.addTask(A);	//test.addToDate(A);
	test.deleteTask(title);

	EXPECT_EQ(test.getDateSize(), 0);
}

TEST(deleteTask, FailedDeletion) {
        string title = "Doggy";
        MainMenu test;

        Task* A = new Task("Doggy", "It's an animal", 3, "Dog");

        test.addTask(A);//old: test.addToDate(A);
        test.deleteTask("Catty");

        EXPECT_NE(test.getDateSize(), 0);
}


/*AddTas*/
TEST(addTask, TaskAddition) {
	MainMenu test;
        Task* A = new Task("Doggy", "It's an animal", 3, "Work");

	test.addTask(A);
	
	EXPECT_EQ((test.getDateSize() +	test.getPrioSize() + test.getTagSize()) / 3, 1);
	
}

TEST(addTask, NewTaskTitle) {
        MainMenu test;
        string total="";
        string title="";
        string desc= "";
        string prio= "";
        string tag= "";
        Task* A = new Task("Doggy", "", 0, "");

        test.addTask(A);

            title=  test.GetDates().at(0)->getTitle();
            desc=  test.GetDates().at(0)->getDesc();
            prio= to_string(test.GetDates().at(0)->getPrio());
            tag= test.GetDates().at(0)->getTag();
            total += title + desc + prio + tag;
        EXPECT_EQ(total, "Doggy0");
}

TEST(addTask, TaskDesc) {
        MainMenu test;
        string total="";
        string title="";
        string desc= "";
        string prio= "";
        string tag= "";
        Task* A = new Task("Doggy", "Poops A lot :)", 0, "");
        
	test.addTask(A);

            title=  test.GetDates().at(0)->getTitle();
            desc=  test.GetDates().at(0)->getDesc();
            prio= to_string(test.GetDates().at(0)->getPrio());
            tag= test.GetDates().at(0)->getTag();
            total += title + desc + prio + tag;
        
        EXPECT_EQ(total, "DoggyPoops A lot :)0");
}
TEST(addTask, TaskPrio) {
        MainMenu test;
        string total="";
        string title="";
        string desc= "";
        string prio= "";
        string tag= "";
        Task* A = new Task("Doggy", "Poops A lot :)", 3, "");
 
        test.addTask(A);

	    title=  test.GetDates().at(0)->getTitle();
            desc=  test.GetDates().at(0)->getDesc();
            prio= to_string(test.GetDates().at(0)->getPrio());
            tag= test.GetDates().at(0)->getTag();
            total += title + desc + prio + tag;

        EXPECT_EQ(total, "DoggyPoops A lot :)3");
}

TEST(addTask, TaskTag) {
        MainMenu test;
        string total="";
        string title="";
        string desc= "";
        string prio= "";
        string tag= "";
        Task* A = new Task("Doggy", "Poops A lot :)", 2, "Other");

        test.addTask(A);

	    title=  test.GetDates().at(0)->getTitle();
            desc=  test.GetDates().at(0)->getDesc();
            prio= to_string(test.GetDates().at(0)->getPrio());
            tag= test.GetDates().at(0)->getTag();
            total += title + desc + prio + tag;

        EXPECT_EQ(total, "DoggyPoops A lot :)2Other");
}
TEST(addTask, TaskRandom) {
        MainMenu test;
        string total="";
        string title="";
        string desc= "";
        string prio= "";
        string tag= "";
        Task* A = new Task("student", "", 1, "Study");

	test.addTask(A);

            title=  test.GetDates().at(0)->getTitle();
            desc=  test.GetDates().at(0)->getDesc();
            prio= to_string(test.GetDates().at(0)->getPrio());
            tag= test.GetDates().at(0)->getTag();
            total += title + desc + prio + tag;

        EXPECT_EQ(total, "student1Study");
}
TEST(addTask, TaskFull) {
        MainMenu test;
        string total="";
        string title="";
        string desc= "";
        string prio= "";
        string tag= "";
        Task* A = new Task("student", "Homwork 4 and Job 2", 1, "Study");

	test.addTask(A);

            title=  test.GetDates().at(0)->getTitle();
            desc=  test.GetDates().at(0)->getDesc();
            prio= to_string(test.GetDates().at(0)->getPrio());
            tag= test.GetDates().at(0)->getTag();
            total += title + desc + prio + tag;

        EXPECT_EQ(total, "studentHomwork 4 and Job 21Study");
}
TEST(addTask, TaskDescTag) {
        MainMenu test;
        string total="";
        string title="";
        string desc= "";
        string prio= "";
        string tag= "";
        Task* A = new Task("student", "I hate my life", 0, "Personal");

	test.addTask(A);

            title=  test.GetDates().at(0)->getTitle();
            desc=  test.GetDates().at(0)->getDesc();
            prio= to_string(test.GetDates().at(0)->getPrio());
            tag= test.GetDates().at(0)->getTag();
            total += title + desc + prio + tag;

        EXPECT_EQ(total, "studentI hate my life0Personal");
}
TEST(addTask, TaskPrioTag) {
        MainMenu test;
        string total="";
        string title="";
        string desc= "";
        string prio= "";
        string tag= "";
        Task* A = new Task("Mom", "", 2, "Business");

        test.addTask(A);

            title=  test.GetDates().at(0)->getTitle();
            desc=  test.GetDates().at(0)->getDesc();
            prio= to_string(test.GetDates().at(0)->getPrio());
            tag= test.GetDates().at(0)->getTag();
            total += title + desc + prio + tag;

        EXPECT_EQ(total, "Mom2Business");
}
TEST(addTask, TaskWeird) {
        MainMenu test;
        string total="";
        string title="";
        string desc= "";
        string prio= "";
        string tag= "";
        Task* A = new Task("Mom", "1.Do This 2.read-_= +*+ UwU @^@ $#%3. Sleep", 1, "Event");

        test.addTask(A);

            title=  test.GetDates().at(0)->getTitle();
            desc=  test.GetDates().at(0)->getDesc();
            prio= to_string(test.GetDates().at(0)->getPrio());
            tag= test.GetDates().at(0)->getTag();
            total += title + desc + prio + tag;

        EXPECT_EQ(total, "Mom1.Do This 2.read-_= +*+ UwU @^@ $#%3. Sleep1Event");
}


TEST(showTask, taskDisplay) {
	MainMenu test;
	Task* A = new Task("Doggy", "It's an animal", 3, "Dog");
	Task* B = new Task("Catto", "It's a monster", 2, "Cat");

	test.addTask(A);
	test.addTask(B);

        EXPECT_EQ(test.getPrintedList(test.GetDates()), test.getPrintedList(test.GetPriorities()));
}


/*

TEST(showTask, moreTests) {

	MainMenu test;
	Task* A = new Task();
	Task* B = new Task();
	Task* C = new Task();

	A->setTitle("Doggy");
	A->setPrio(1);
	B->setTitle("Catto");
	C->setTitle("Tortle");
	C->setDesc("It's a reptile");
	C->setDay(02);
	C->setMonth(04);
	C->setYear(2001);
	
	test.addTask(A);
	test.addTask(B);
	test.addTask(C);


	EXPECT_EQ(test.getPrintedList(test.GetDates()),test.getPrintedList(test.GetPriorities()));

}
*/

/*
//INSERT YOUR TESTS ABOVE (MINE CAN GET ANNOYING) anyone know how to expect user input?

TEST(editTitle, KittyToBunny) {
        MainMenu test;

        Task* A = new Task("Doggy", "It's an animal", 3, "Dog");
        Task* B = new Task("Kitty", "It's an animal", 2, "Rabbit");

	test.addTask(A);
	test.addTask(B);
	test.editTask();	

	string newTitle = test.GetDates().at(1)->getTitle();
	EXPECT_EQ(newTitle, "Bunny");
}

TEST(editTitle, DoggyToPuppy) {
        MainMenu test;

        Task* A = new Task("Doggy", "It's an animal", 3, "Dog");
        Task* B = new Task("Kitty", "It's an animal", 2, "Rabbit");

        test.addTask(A);
        test.addTask(B);
        test.editTask();

        string newTitle = test.GetDates().at(0)->getTitle();
        EXPECT_EQ(newTitle, "Puppy");
}

TEST(editDesc, DoggyToNICE) {
        MainMenu test;

        Task* A = new Task("Doggy", "It's an animal", 3, "Dog");
        Task* B = new Task("Kitty", "It's an animal", 2, "Rabbit");

        test.addTask(A);
        test.addTask(B);

        test.editTask();

        string newDesc = test.GetDates().at(0)->getDesc();
        EXPECT_EQ(newDesc, "NICE");
}

TEST(editTag, DoggyToHeck) {
        MainMenu test;

        Task* A = new Task("Doggy", "It's an animal", 3, "Dog");
        Task* B = new Task("Kitty", "It's an animal", 2, "Rabbit");

        test.addTask(A);
        test.addTask(B);

        test.editTask();

        string newTag = test.GetDates().at(0)->getTag();
        EXPECT_EQ(newTag, "Heck");
}

TEST(editPrio, KittyTo1) {
        MainMenu test;

        Task* A = new Task("Doggy", "It's an animal", 3, "Dog");
        Task* B = new Task("Kitty", "It's an animal", 2, "Rabbit");

        test.addTask(A);
        test.addTask(B);

        test.editTask();

        int newPrio = test.GetDates().at(1)->getPrio();
        EXPECT_EQ(newPrio, 1);
}

*/

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }

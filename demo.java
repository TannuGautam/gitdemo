import java.util.*;

public class demo {
    public static Scanner scn = new Scanner(System.in);

    public static void demoAL() {
        // create
        ArrayList<Integer> list = new ArrayList<>();

        // add 
        list.add(10);
        list.add(20);
        list.add(30);
        list.add(40);
        list.add(50);
        list.add(60);

        System.out.println(list + ", size : " + list.size());
        // Add At
        list.add(3, 35);
        System.out.println(list + ", size : " + list.size());


        // get At
        int val = list.get(3);
        System.out.println("After GET at 3rd index : " + val);
        // get Last
        int last = list.get(list.size() - 1);
        System.out.println("After GET at last index : " + last);

        // set At
        list.set(3, 39);
        System.out.println(list + ", size : " + list.size());

        // remove 
        int rmVal = list.remove(3);
        System.out.println("Removal value is : " + rmVal);

        // printing arrayList using loop -> normal loop
        for(int i = 0; i < list.size(); i++) {
            int value = list.get(i);
            System.out.print(value + " ");
        }
        System.out.println();
        // for each loop
        for(int ele : list) {
            System.out.print(ele + " ");
        }
        System.out.println();


    }

    public static void demoString() {
        // declare , initialise
        String s = "Hello World";
        // input
        // String s1 = scn.next();
        // String s2 = scn.nextLine();
        // System.out.println(s2);

        // char At, set is not allowed in string of java
        char ch = s.charAt(4);
        System.out.println(ch);

        // ouput with loop
        for(int i = 0; i < s.length(); i++) {
            char chr = s.charAt(i);
            System.out.print(chr);
        }
        System.out.println();

        // Substring
        // String str = s.substring(6, 11);
        // System.out.println(str);

        // str = s.substring(6, 8);
        // System.out.println(str);

        // str = s.substring(6);
        // System.out.println(str);

        // cancatenation
        s = "Hello";
        s += ' ';
        s += 'W';
        s += 'o';
        System.out.println(s);
        s += "rld";
        System.out.println(s);

        System.out.println(s + 13 + 7);
        System.out.println(13 + 7 + s);
        System.out.println(13 + 7 + s + 10 + 2);
        System.out.println(13 + 7 + s + (10 + 2));

    }

    public static void main(String[] args) {
        // demoAL();
        demoString();
    }
}
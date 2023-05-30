package org.tavex;


import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner("."+ File.separator+"palavras.txt");
        SortedMap<String,Integer> lista = new TreeMap<String,Integer>();
        List<String> listaCerta = new LinkedList<>();

        while(in.hasNext()) {
            String palavra = in.next();
            if(lista.containsKey(palavra)) {
                lista.replace(palavra,lista.get(palavra),lista.get(palavra) + 1);
            } else {
                lista.put(in.next(),1);
            }
            listaCerta.add(palavra);
        }


    }

}
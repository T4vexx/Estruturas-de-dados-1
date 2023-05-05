package org.tavex;

import java.nio.Buffer;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int opt = 0;

        do {
            System.out.println("Digite a opção desejada:\n>0 - Registrar conta\n>1 - Logar conta\n>2 - Sair");
            opt = in.nextInt();

            switch (opt) {
                case 0:
                    registrar(in);
                    break;
                case 1:
                    logar(in);
                    break;
                case 2:
                    break;
            }

        } while(!(opt < 0 || opt > 2));

        in.close();
    }

    static public void registrar(Scanner in) {
        String nome;
        String usuario;
        String senha;

        System.out.println("Digite seu nome completo");
        nome = in.nextLine();
        System.out.println("Digite um nome de usuario");
        usuario = in.nextLine();
        System.out.println("Digite uma senha");
        senha = in.nextLine();

        senha = BCry
    }

    static public void logar(Scanner in) {

    }
}
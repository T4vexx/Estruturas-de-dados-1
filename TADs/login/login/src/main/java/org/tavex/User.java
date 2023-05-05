package org.tavex;

import java.io.Serializable;

public class User implements Serializable {
    private String nomeCompleto;
    private String nomeUsuario;
    private String senha;

    public User(String nomeCompleto, String nomeUsuario, String senha) {
        this.nomeCompleto = nomeCompleto;
        this.nomeUsuario = nomeUsuario;
        this.senha = senha;
    }

    public String getNomeCompleto() {
        return nomeCompleto;
    }

    public String getNomeUsuario() {
        return nomeUsuario;
    }

    public String getSenha() {
        return senha;
    }
}

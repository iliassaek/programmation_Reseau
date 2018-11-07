# programmation_reseau

## 1-Initialisation d'une adresse
address.c

## 2-Obtention de l'adresse IP
host.c

## 3-serveur echo
serveurecho.c

## 4-client echo
clientecho.c

## 5-scanneur de port
scan.c

## 6-atelier 6
clientDate.c

serveurDate.c

a. done : le serveur ne transmet que l'heure si vous tapez HEURE au client

b. done : le serveur ne transmet que la date si vous tapez DATE au client

c. done : le serveur transmet l'heure et la date si vous tapez HEUREDATE en telnet

d. done : le serveur ferme la connexion si vous tapez ExiT

## 7-serveur multiclient

Un petit serveur supportant plusieurs connexions

via des clients telnet

telnet 127.0.0.1 9090

HEURE

DATE

HEUREDATE

EXIT

sinon echo le message

multiServEcho.c

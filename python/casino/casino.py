#!/usr/bin/python3
import random

#La roulette est constituée de 50 cases allant naturellement de 0 à 49.
# Les numéros pairs sont de couleur noire, les numéros impairs sont de couleur rouge.
# Le croupier lance la roulette, lâche la bille et quand la roulette s'arrête, relève le numéro de la case dans laquelle la bille s'est arrêtée.
# Dans notre programme, nous ne reprendrons pas tous ces détails « matériels »
# mais ces explications sont aussi à l'intention de ceux qui ont eu la chance d'éviter les salles de casino jusqu'ici.
# Le numéro sur lequel s'est arrêtée la bille est, naturellement, le numéro gagnant.

# Si le numéro gagnant est celui sur lequel le joueur a misé (probabilité de 1/50, plutôt faible), le croupier lui remet 3 fois la somme misée.

# Sinon, le croupier regarde si le numéro misé par le joueur est de la même couleur que le numéro gagnant
# (s'ils sont tous les deux pairs ou tous les deux impairs).
# Si c'est le cas, le croupier lui remet 50 % de la somme misée.
# Si ce n'est pas le cas, le joueur perd sa mise.

argent = 10
mise_case = -1
mise_argent = -1
win_case = -1

def mise():
    global mise_case, argent, mise_argent

    while mise_case >= 50 or mise_case < 0:
        mise_case = int(input("Misez sur une case : "))
        if mise_case >= 50 or mise_case < 0:
            print("Vous ne pouvez pas miser sur la case " + str(mise_case))

    while mise_argent > argent or mise_argent < 0:
        mise_argent = int(input("Combien d'argent voulez vous miser : "))
        if mise_argent > argent or mise_argent < 0:
            print("Vous ne pouvez pas miser " + str(mise_argent))
            print("Votre solde est de " + str(argent))
    argent = argent - mise_argent
    print("vous avez misé " + str(argent) + "$ sur la case " + str(mise_case) + " (" + returnColor(mise_case) + ")")


def returnColor(case):
    if (case % 2) == 0:
        return "noire"
    return "rouge"

def checkColor(case, mise):
    if (case % 2) == (mise % 2):
        return 1
    return 0

def spin():
    global win_case
    print("Les jeux sont faits")
    win_case = random.randint(0, 49)


while argent > 0:
    print("Votre solde est de " + str(argent) + "$")
    mise()
    spin()
    print("Vous êtes tombé sur la case " + str(win_case) + " de la couleur " + returnColor(win_case))
    if win_case == mise_case:
        print("Félicitation ! Vous avez gagné " + str(mise_argent * 3))
        argent = argent + (mise_argent * 3)
    elif checkColor(win_case, mise_case):
        print("Bravo ! Vous êtes tombé sur la bonne couleur. Vous avez gagné " + str(mise_argent/2))
        argent = argent + (mise_argent / 2)
    else:
        print("Perdu !")
    mise_case = -1
    mise_argent = -1
    win_case = -1
    print("----------------------")
print("Fin de la partie")
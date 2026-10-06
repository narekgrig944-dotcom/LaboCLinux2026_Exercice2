#include "FichierUtilisateur.h"
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

int estPresent(const char* nom)
{
  int fd = open(FICHIER_UTILISATEURS, O_RDONLY);
  if (fd == -1)
  {
    return -1;
  }

  UTILISATEUR u;
  int position = 0;

  while (read(fd, &u, sizeof(UTILISATEUR)) == sizeof(UTILISATEUR))
  {
    position++;
    if (strcmp(u.nom, nom) == 0)
    {
      close(fd);
      return position;
    }
  }

  close(fd);
  return 0;
}

////////////////////////////////////////////////////////////////////////////////////
int hash(const char* motDePasse)
{
  int somme = 0;
  for (int i = 0; motDePasse[i] != '\0'; i++)
  {
    somme += (i + 1) * motDePasse[i];
  }
  return somme % 97;
}

////////////////////////////////////////////////////////////////////////////////////
void ajouteUtilisateur(const char* nom, const char* motDePasse)
{
  int fd = open(FICHIER_UTILISATEURS, O_WRONLY | O_APPEND | O_CREAT, 0644);

  UTILISATEUR u;
  strcpy(u.nom, nom);
  u.hash = hash(motDePasse);

  write(fd, &u, sizeof(UTILISATEUR));
  close(fd);
}

////////////////////////////////////////////////////////////////////////////////////
int verifieMotDePasse(int pos, const char* motDePasse)
{
  int fd = open(FICHIER_UTILISATEURS, O_RDONLY);
  if (fd == -1)
  {
    return -1;
  }

  lseek(fd, (pos - 1) * sizeof(UTILISATEUR), SEEK_SET);

  UTILISATEUR u;
  read(fd, &u, sizeof(UTILISATEUR));
  close(fd);

  if (hash(motDePasse) == u.hash)
  {
    return 1;
  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////////////
int listeUtilisateurs(UTILISATEUR *vecteur)
{
  int fd = open(FICHIER_UTILISATEURS, O_RDONLY);
  if (fd == -1)
  {
    return -1;
  }

  int count = 0;
  while (read(fd, &vecteur[count], sizeof(UTILISATEUR)) == sizeof(UTILISATEUR))
  {
    count++;
  }

  close(fd);
  return count;
}

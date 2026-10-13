# ---------------------------------------------------------------
# Makefile per compilare uno o più esercizi C
# Uso: make <percorso/senza_estensione>
#      make FILE=<percorso/senza_estensione>   (forma alternativa)
# ---------------------------------------------------------------

CC     = gcc
CFLAGS = -std=c11 -Wall -O2 -g
LDLIBS = -lm

# Disattiva regole implicite e variabili built-in
MAKEFLAGS += -rR
.SUFFIXES:

.PHONY: all clean

# Esercizi richiesti: target sulla riga di comando e/o FILE=...
# (si toglie l'eventuale .c e si eliminano i duplicati)
ESERCIZI := $(sort $(patsubst %.c,%,$(FILE) $(filter-out all clean,$(MAKECMDGOALS))))
BINS     := $(foreach e,$(ESERCIZI),$(dir $(e))bin/$(notdir $(e)))
IS_CLEAN := $(filter clean,$(MAKECMDGOALS))

ifeq ($(strip $(ESERCIZI)),)

# ---- Nessun esercizio specificato: messaggio di utilizzo ed errore ----
all clean:
	@printf '%s\n' \
	  'Errore: nessun esercizio specificato.' \
	  '' \
	  'Uso:' \
	  '  make <percorso/senza_estensione>         compila' \
	  '  make clean <percorso/senza_estensione>   elimina l eseguibile' \
	  '' \
	  'Esempio:' \
	  '  make ConfrontaStringhe/minimo' \
	  '  ./ConfrontaStringhe/bin/minimo' >&2
	@exit 1

else

# Modello di regole per un singolo esercizio ($(1) = percorso senza .c)
define REGOLE_ESERCIZIO
.PHONY: $(1)
$(1): $(if $(IS_CLEAN),,$(dir $(1))bin/$(notdir $(1)))

$(dir $(1))bin/$(notdir $(1)): $(1).c
	@mkdir -p $$(@D)
	$(CC) $(CFLAGS) $$< -o $$@ $(LDLIBS)

$(1).c:
	@echo "Errore: il file sorgente '$$@' non esiste." >&2
	@exit 1
endef

$(foreach e,$(ESERCIZI),$(eval $(call REGOLE_ESERCIZIO,$(e))))

all: $(ESERCIZI)

# Elimina solo gli eseguibili (e le bin/ se restano vuote)
clean:
	rm -f $(BINS)
	@rmdir $(dir $(BINS)) 2>/dev/null || true

endif
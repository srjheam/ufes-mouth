#include <stdio.h>

void main(void) {
	int nDelegacoes = 0;

	int m_delCampId = 1, m_delCampSom = 0;
	int f_delCampId = 1, f_delCampSom = 0;

	scanf("%d", &nDelegacoes);

	int i;
	for (i = 1; i <= nDelegacoes; i++) {
		int m_mlhId = 0, m_mlhMaxNota = 0, m_mlhMedNota = 0, m_mlhMinNota = 0;
		int f_mlhId = 0, f_mlhMaxNota = 0, f_mlhMedNota = 0, f_mlhMinNota = 0;

		int m_piorId = 1, m_piorMaxNota = __INT_MAX__, m_piorMedNota = __INT_MAX__, m_piorMinNota = __INT_MAX__;
		int f_piorId = 1, f_piorMaxNota = __INT_MAX__, f_piorMedNota = __INT_MAX__, f_piorMinNota = __INT_MAX__;

		int m_currCampSom = 0;
		int f_currCampSom = 0;
		while (1) {
			char sexo;
			int id, nota1, nota2, nota3;

			scanf("%d ", &id);
			if (id == -1)
				break;

			scanf("%c %d %d %d", &sexo, &nota1, &nota2, &nota3);

			int currMaxNota = 0, currMedNota = 0, currMinNota = 0;
			if (nota1 > nota2) {
				if (nota1 > nota3) {
					currMaxNota = nota1;
					if (nota3 > nota2) {
						currMedNota = nota3;
						currMinNota = nota2;
					}
					else {
						currMedNota = nota2;
						currMinNota = nota3;
					}
				}
				else {
					currMaxNota = nota3;
					currMedNota = nota1;
					currMinNota = nota2;
				}
			}
			else {
				if (nota2 > nota3) {
					currMaxNota = nota2;
					if (nota3 > nota1) {
						currMedNota = nota3;
						currMinNota = nota1;
					}
					else {
						currMedNota = nota1;
						currMinNota = nota3;
					}
				}
				else {
					currMaxNota = nota3;
					currMedNota = nota2;
					currMinNota = nota1;
				}
			}

			int isMlh = 0;
			int isPior = 0;
			switch (sexo) {
			case 'M':
				if (currMaxNota > m_mlhMaxNota) {
					isMlh++;
				}
				else if (currMaxNota == m_mlhMaxNota) {
					if (currMedNota > m_mlhMedNota) {
						isMlh++;
					}
					else if (currMedNota == m_mlhMedNota) {
						if (currMinNota > m_mlhMinNota) {
							isMlh++;
						}
						else if (currMinNota == m_mlhMinNota && id < m_mlhId) {
							isMlh++;
						}
					}
				}

				if (currMaxNota < m_piorMaxNota) {
					isPior++;
				}
				else if (currMaxNota == m_piorMaxNota) {
					if (currMedNota < m_piorMedNota) {
						isPior++;
					}
					else if (currMedNota == m_piorMedNota) {
						if (currMinNota < m_piorMinNota) {
							isPior++;
						}
						else if (currMinNota == m_piorMinNota && id > m_piorId) {
							isPior++;
						}
					}
				}

				if (isMlh) {
					m_mlhId = id;
					m_mlhMaxNota = currMaxNota;
					m_mlhMedNota = currMedNota;
					m_mlhMinNota = currMinNota;
				}
				if (isPior) {
					m_piorId = id;
					m_piorMaxNota = currMaxNota;
					m_piorMedNota = currMedNota;
					m_piorMinNota = currMinNota;
				}

				m_currCampSom += currMaxNota;
				break;

			case 'F':
				if (currMaxNota > f_mlhMaxNota) {
					isMlh++;
				}
				else if (currMaxNota == f_mlhMaxNota) {
					if (currMedNota > f_mlhMedNota) {
						isMlh++;
					}
					else if (currMedNota == f_mlhMedNota) {
						if (currMinNota > f_mlhMinNota) {
							isMlh++;
						}
						else if (currMinNota == f_mlhMinNota && id < f_mlhId) {
							isMlh++;
						}
					}
				}

				if (currMaxNota < f_piorMaxNota) {
					isPior++;
				}
				else if (currMaxNota == f_piorMaxNota) {
					if (currMedNota < f_piorMedNota) {
						isPior++;
					}
					else if (currMedNota == f_piorMedNota) {
						if (currMinNota < f_piorMinNota) {
							isPior++;
						}
						else if (currMinNota == f_piorMinNota && id > f_piorId) {
							isPior++;
						}
					}
				}

				if (isMlh) {
					f_mlhId = id;
					f_mlhMaxNota = currMaxNota;
					f_mlhMedNota = currMedNota;
					f_mlhMinNota = currMinNota;
				}
				if (isPior) {
					f_piorId = id;
					f_piorMaxNota = currMaxNota;
					f_piorMedNota = currMedNota;
					f_piorMinNota = currMinNota;
				}

				f_currCampSom += currMaxNota;
				break;
			}

		}

		printf("MELHORES ATLETAS DA DELEGACAO %d\n", i);
		printf("MASCULINO: %d FEMININO: %d\n", m_mlhId, f_mlhId);
		printf("PIORES ATLETAS DA DELEGACAO %d\n", i);
		printf("MASCULINO: %d FEMININO: %d\n\n", m_piorId, f_piorId);

		if (m_currCampSom > m_delCampSom) {
			m_delCampId = i;
			m_delCampSom = m_currCampSom;
		}
		if (f_currCampSom > f_delCampSom) {
			f_delCampId = i;
			f_delCampSom = f_currCampSom;
		}
	}

	printf("%s", "DELEGACAO CAMPEA:\n");
	printf("MASCULINO: %d FEMININO: %d", m_delCampId, f_delCampId);
}


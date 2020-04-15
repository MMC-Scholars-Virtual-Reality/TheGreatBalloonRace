// This software is under partial ownership by The Ohio State University, for it is a product of student employees. For official policy, see https://tco.osu.edu/sites/default/files/pdfs/IP-Policy.pdf or contact The Ohio State University Office of Legal Affairs.

#include "Timer.h"

FString UTimer::GetText() {
	FString text;
	if (!m_pGameWorld) {
		m_pGameWorld = GetWorld();
		m_pGameMode = m_pGameWorld->GetAuthGameMode<ATheGreatBalloonRaceGameModeBase>();
	}
	m_iTimeLeft = m_pGameMode->m_iTimeLimit - m_pGameWorld->GetTimeSeconds();
	
	text.Append(SecondsToMSS(m_iTimeLeft));
	
	return text;
}

FString UTimer::SecondsToMSS(int seconds) {
	int minutes = seconds / 60;
	FString time = FString("Time: ");

	time.AppendInt(minutes);
	time.AppendChar(':');

	seconds %= 60;
	if (seconds < 10) {
		time.AppendChar('0');
	}
	time.AppendInt(seconds);

	return time;
}

int UTimer::GetTimeLeft() {
	return m_iTimeLeft;
}

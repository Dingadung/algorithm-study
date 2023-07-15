package sejong.reserve.service;


import lombok.RequiredArgsConstructor;
import org.springframework.mail.SimpleMailMessage;
import org.springframework.mail.javamail.JavaMailSender;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import sejong.reserve.domain.Reservation;
import sejong.reserve.dto.ReservationDto;


@RequiredArgsConstructor
@Service
public class EmailService {

    private final JavaMailSender mailSender;


    @Transactional
    public void sendReservationReminder(String recipientEmail, ReservationDto reservation){
        SimpleMailMessage message = new SimpleMailMessage();
        message.setFrom("sejongreservation1234@gmail.com"); // 여기에 발신 이메일 주소를 넣으세요
        message.setTo(recipientEmail);
        message.setSubject("당신의 예약이 1시간 남았습니다!");
        message.setText("예약 시작 시간: " + reservation.getReservationTime());
        mailSender.send(message);
    }


@Transactional
    public void sendSimpleMessage(String to, String subject, String text) {
        SimpleMailMessage message = new SimpleMailMessage();
        message.setFrom("sejongreservation1234@gmail.com");
        message.setTo(to);
        message.setSubject(subject);
        message.setText(text);
        mailSender.send(message);
    }
}

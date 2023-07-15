package sejong.reserve.service;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.data.domain.Pageable;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import sejong.reserve.domain.*;
import sejong.reserve.dto.ReservationsDto;
import sejong.reserve.dto.TimeDto;
import sejong.reserve.repository.ReservationRepository;

import java.time.LocalDateTime;
import java.time.Month;
import java.time.ZoneId;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

@Service
@Slf4j
@RequiredArgsConstructor
@Transactional(readOnly = true)
public class ReservationService {
    private final ReservationRepository reservationRepository;
    private final EmailReminderService emailNotificationService;

    @Transactional
    public Long makeReservation(Reservation reservation) {
        log.info("예약 시작: {}", reservation);
        Reservation savedReservation = reservationRepository.save(reservation);
        log.info("예약 완료: {}", savedReservation);
        return savedReservation.getId();
    }


    // 전체 예약 리스트
    public List<ReservationsDto> managerList() {
        log.info("전체 예약 리스트 조회 시작");
        List<Reservation> resultList = reservationRepository.findAll();
        List<ReservationsDto> reservationsDtoList = convertToDto(resultList);
        log.info("전체 예약 리스트 조회 완료: {}개의 예약이 있습니다.", resultList.size());
        return reservationsDtoList;
    }

    // 학생별 예약 리스트
    public List<ReservationsDto> userList(String student_no) {
        log.info("학생별 예약 리스트 조회 시작: 학생 번호 {}", student_no);
        List<Reservation> reservations = reservationRepository.findByStudentNo(student_no);
        List<ReservationsDto> reservationDtoList = convertToDto(reservations);
        log.info("학생별 예약 리스트 조회 완료: {}개의 예약이 있습니다.", reservationDtoList.size());
        return reservationDtoList;
    }

    private List<ReservationsDto> convertToDto(List<Reservation> reservations) {
        List<ReservationsDto> reservationDtoList = new ArrayList<>();
        for(Reservation reservation: reservations) {
            ReservationsDto reservationsDto = new ReservationsDto(reservation);
            reservationDtoList.add(reservationsDto);
        }
        return reservationDtoList;
    }

    /**
     *
     * 예약 상태별 리스트
     */
    public List<ReservationsDto> userListStatus(String student_no, ReservationStatus status) {
        List<Reservation> reservations = reservationRepository.findByStudentNoAndStatus(student_no, status);
        List<ReservationsDto> reservationDtoList = convertToDto(reservations);
        return reservationDtoList;
    }

    // 예약 id 를 통한 예약 정보
    public Optional<Reservation> getReservation(Long reservation_id) {
        Optional<Reservation> reservation = reservationRepository.findById(reservation_id);
        return reservation;
    }

    public Boolean isPossibleTime(LocalDateTime start, LocalDateTime end, Long roomId) {
        ZoneId localZone = ZoneId.systemDefault();
        log.info("localZone = {}", localZone);
        int timeCnt = reservationRepository.isPossibleTime(start, end, roomId);
        if(timeCnt == 0) {
            return true;
        } else {
            return false;
        }
    }

    public LocalDateTime getStartTime(Long reservation_id) {
        return reservationRepository.getStartTime(reservation_id);
    }

    public LocalDateTime getEndTime(Long reservation_id) {
        return reservationRepository.getEndTime(reservation_id);
    }

    @Transactional
    public void setStatus(ReservationStatus status, Long reservation_id) {
        log.info("예약 상태 변경 시작: 예약 ID = {}, 상태 = {}", reservation_id, status);
        Optional<Reservation> reservation = reservationRepository.findById(reservation_id);
        Reservation reservationReal = reservation.get();
        reservationReal.setStatus(status);
        log.info("예약 상태 변경 완료");

    }

    @Transactional
    public void deleteOne(Long reservation_id) {
        log.info("예약 삭제 시작: 예약 ID = {}", reservation_id);
        reservationRepository.deleteById(reservation_id);
        log.info("예약 삭제 완료");

    }

    @Transactional
    public void deleteAll(String student_no) {
        log.info("학생의 모든 예약 삭제 시작: 학생 번호 = {}", student_no);
        List<Reservation> reservations = reservationRepository.findByStudentNo(student_no);
        reservationRepository.deleteAll(reservations);
        log.info("학생의 모든 예약 삭제 완료");

    }

    @Transactional
    public void reset() {
        log.info("모든 예약 삭제 시작");
        reservationRepository.deleteAll();
        log.info("모든 예약 삭제 완료");
    }

    public List<Reservation> getStatusList(String student_no, ReservationStatus status) {
        log.info("학생의 예약 상태 리스트 조회 시작: 학생 번호 = {}, 상태 = {}", student_no, status);
        List<Reservation> resultList = reservationRepository.getStatusList(student_no, status);
        log.info("학생의 예약 상태 리스트 조회 완료: {}개의 예약이 있습니다.", resultList.size());
        return reservationRepository.getStatusList(student_no, status);
    }

    @Transactional
    public void cancel(Long reservation_id) {
        log.info("예약 취소 시작: 예약 ID = {}", reservation_id);
        Optional<Reservation> reservation = reservationRepository.findById(reservation_id);
        Reservation reservationReal = reservation.get();
        reservationReal.setStart(null);
        reservationReal.setEnd(null);
        log.info("예약 취소 완료");
    }

    public List<TimeDto> getTodayTimeListRoom(LocalDateTime todayDate, Long roomId) {
        int year = todayDate.getYear();
        Month month = todayDate.getMonth();
        int day = todayDate.getDayOfMonth();
        LocalDateTime todayStart = LocalDateTime.of(year, month, day, 0, 0);
        LocalDateTime todayEnd = LocalDateTime.of(year, month, day, 23, 59);

        List<Reservation> reservations = reservationRepository.getTodayTimeListRoom(todayStart, todayEnd, roomId);
        List<TimeDto> timeList = new ArrayList<>();
        for(Reservation reservation:reservations) {
            LocalDateTime start = reservation.getStart();
            LocalDateTime end = reservation.getEnd();
            TimeDto time = new TimeDto(start, end);
            timeList.add(time);
        }
        return timeList;
    }

    public int getTodayReserveCntByRoom(LocalDateTime todayDate, Long roomId) {
        int year = todayDate.getYear();
        Month month = todayDate.getMonth();
        int day = todayDate.getDayOfMonth();

        LocalDateTime todayStart = LocalDateTime.of(year, month, day, 0, 0);
        LocalDateTime todayEnd = LocalDateTime.of(year, month, day, 23, 59);
        int todayReserveCnt = reservationRepository.getTodayReserveCntByRoom(todayStart, todayEnd, roomId);
        return todayReserveCnt;
    }

    public int getTodayReserveCntAll(LocalDateTime todayDate) {
        int year = todayDate.getYear();
        Month month = todayDate.getMonth();
        int day = todayDate.getDayOfMonth();

        LocalDateTime todayStart = LocalDateTime.of(year, month, day, 0, 0);
        LocalDateTime todayEnd = LocalDateTime.of(year, month, day, 23, 59);
        int todayReserveCnt = reservationRepository.getTodayReserveCntAll(todayStart, todayEnd);
        return todayReserveCnt;
    }

    public List<Integer> getMonthReserveCheck(int year, Month month, Long roomId) {
        List<Integer> monthCheck = new ArrayList<>();

        LocalDateTime today = LocalDateTime.of(year, month, month.minLength(), 0, 0);
        int day = 1;
        while(day <= month.maxLength()) {
            today = LocalDateTime.of(year, month, day++, 0, 0);
            monthCheck.add(getTodayReserveCntByRoom(today, roomId));
        }
        return monthCheck;
    }


    public int[] getTodayTimeCheckRoom(LocalDateTime todayDate, Long roomId) {
        int year = todayDate.getYear();
        Month month = todayDate.getMonth();
        int day = todayDate.getDayOfMonth();
        LocalDateTime todayStart = LocalDateTime.of(year, month, day, 0, 0);
        LocalDateTime todayEnd = LocalDateTime.of(year, month, day, 23, 59);


        int[] todayTimeCheck = new int[]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        List<Reservation> reservations = reservationRepository.getTodayTimeListRoom(todayStart, todayEnd, roomId);

        for(Reservation reservation:reservations) {
            LocalDateTime start = reservation.getStart();
            LocalDateTime end = reservation.getEnd();
            log.info("start = {}, end = {}", start, end);

            int startHour = start.getHour();
            int endHour = end.getHour();

            for(int i=startHour;i<=endHour;i++) {
                todayTimeCheck[i] = 1;
            }
        }
        return todayTimeCheck;
    }

    public List<ReservationsDto> getReservationListBySno(String student_no) {
        List<Reservation> reservations = reservationRepository.getReservationListBySno(student_no);
        List<ReservationsDto> reservationDtoList = convertToDto(reservations);
        return reservationDtoList;
    }

    public List<ReservationsDto> getReservationListByDate(LocalDateTime dateStart, LocalDateTime dateEnd) {
        List<Reservation> reservations = reservationRepository.getReservationListByDate(dateStart, dateEnd);
        List<ReservationsDto> reservationDtoList = convertToDto(reservations);
        return reservationDtoList;
    }

    public List<ReservationsDto> getReservationListByDateAndStatus(LocalDateTime dateStart, LocalDateTime dateEnd, ReservationStatus status) {
        List<Reservation> reservations = reservationRepository.getReservationListByDateAndStatus(dateStart, dateEnd, status);
        List<ReservationsDto> reservationDtoList = convertToDto(reservations);
        return reservationDtoList;
    }

    public void checkNoShow(Long reservation_id, boolean check) {
        Reservation reservation = reservationRepository.findById(reservation_id).get();
        reservation.setNoShowCheck(check);
    }

    public List<ReservationsDto> getReservationListBySnoAndStatus(String student_no, ReservationStatus status) {
        List<Reservation> reservations = reservationRepository.getReservationListBySnoAndStatus(student_no, status);
        List<ReservationsDto> reservationDtoList = convertToDto(reservations);
        return reservationDtoList;
    }

    public Integer getReserveCntAll() {
        int reserveCntAll = reservationRepository.getReserveCntAll(ReservationStatus.FINISHED);
        return reserveCntAll;
    }

    public Integer getReserveCntByAuthority(AuthState authority) {
        int reserveCntByAuthority = reservationRepository.getReserveCntByAuthority(authority, ReservationStatus.FINISHED);
        return reserveCntByAuthority;
    }

    public Integer getReserveCntBySno(String sno) {
        int reserveCntByAuthority = reservationRepository.getReserveCntBySno(sno, ReservationStatus.FINISHED);
        return reserveCntByAuthority;
    }

    public int[] getTodayTimeCheck(LocalDateTime todayDate) {
        int year = todayDate.getYear();
        Month month = todayDate.getMonth();
        int day = todayDate.getDayOfMonth();
        LocalDateTime todayStart = LocalDateTime.of(year, month, day, 0, 0);
        LocalDateTime todayEnd = LocalDateTime.of(year, month, day, 23, 59);


        int[] todayTimeCheck = new int[]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        List<Reservation> reservations = reservationRepository.getTodayTimeList(todayStart, todayEnd);

        for(Reservation reservation:reservations) {
            LocalDateTime start = reservation.getStart();
            LocalDateTime end = reservation.getEnd();
            log.info("start = {}, end = {}", start, end);

            int startHour = start.getHour();
            int endHour = end.getHour();

            for(int i=startHour;i<=endHour;i++) {
                todayTimeCheck[i] = 1;
            }
        }
        return todayTimeCheck;
    }

    public List<ReservationsDto> getTodayTimeList(LocalDateTime todayDate) {
        int year = todayDate.getYear();
        Month month = todayDate.getMonth();
        int day = todayDate.getDayOfMonth();
        LocalDateTime todayStart = LocalDateTime.of(year, month, day, 0, 0);
        LocalDateTime todayEnd = LocalDateTime.of(year, month, day, 23, 59);

        List<Reservation> reservations = reservationRepository.getTodayTimeList(todayStart, todayEnd);
        List<ReservationsDto> reservationsDtoList = convertToDto(reservations);

        return reservationsDtoList;
    }

    @Transactional
    public void setNoShowStatus(Long reservationId) {
        Reservation reservation = reservationRepository.findById(reservationId).get();
        reservation.setNoShowCheck(true);
    }



}
